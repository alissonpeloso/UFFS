#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll INF = 9999999;

vector<ll> digits;
vector<bool> ready;
vector<ll> value;

ll solveIterative(ll x) {
    value[0] = 0;
    for (int i = 1; i <= x; i++) {
        value[i] = INF;
        for (auto c : digits) {
            if (i-c >= 0) {
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }
    return value[x];
}

int main()
{
    ll x, n;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        digits.push_back(a);
    }

    value.reserve(x+1);

    ll result = solveIterative(x);

    if(result == INF){
        cout << -1 << endl;
        return 0;
    }
    
    cout << solveIterative(x) << endl;

    return 0;
}