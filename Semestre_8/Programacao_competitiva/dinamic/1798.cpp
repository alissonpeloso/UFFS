#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,t;
    cin >> n >> t;

    vector<ll> pipe(n);
    vector<ll> weights(n);

    for(ll i = 0; i < n; i++){
        cin >> pipe[i] >> weights[i];
    }

    vector<ll> value(t+1);

    value[0] = 0;
    for (int x = 1; x <= t; x++) {
        value[x] = 0;
        for (int c = 0; c < n; c++) {
            if (x-pipe[c] >= 0) {
                value[x] = max(value[x], value[x-pipe[c]] + weights[c]);
            }
        }
    }

    cout << *max_element(value.begin(), value.end()) << endl;
}