#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll m = 1e9+7;
    ll n,x;
    cin >> n >> x;

    vector<ll> coins(n);
    vector<ll> value(x+1);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    value[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i-c >= 0) {
                value[i] += value[i-c];
                value[i] %= m;
            }
        }
    }

    cout << value[x] << endl;
}