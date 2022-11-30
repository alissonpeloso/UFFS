#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll INF = 9999999;
ll conta = 0;

vector<ll> coins = {1, 3, 4};
vector<bool> ready;
vector<ll> value;

ll solve(ll x) {
    conta++;
    if (x < 0) return INF;
    if (x == 0) return 0;
    ll best = INF;
    for (auto c : coins) {
        best = min(best, solve(x - c)+1);
    }
    return best;
}

ll solveMemo(ll x) {
    conta++;
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    ll best = INF;
    for (auto c : coins) {
        best = min(best, solveMemo(x - c)+1);
    }
    value[x] = best;
    ready[x] = true;
    return best;
}

ll solveIterative(ll x) {
    value[0] = 0;
    for (int i = 1; i <= x; i++) {
        value[i] = INF;
        for (auto c : coins) {
            if (i-c >= 0) {
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }
    return value[x];
}

int main()
{
    ll x;
    cin >> x;

    ready.reserve(x+1);
    value.reserve(x+1);
    
    cout << solveIterative(x) << endl;
    cout << conta << endl;

    return 0;
}