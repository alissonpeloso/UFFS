#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll INF = 9999999;

vector<ll> value;

vector<ll> getDigits(ll x) {
    vector<ll> digits;
    while (x > 0) {
        digits.push_back(x%10);
        x /= 10;
    }
    return digits;
}

int main()
{
    ll n;
    cin >> n;

    value.reserve(n+1);

    value[0] = 0;
    for (int i = 1; i <= n; i++) {
        value[i] = INF;
        vector<ll> digits = getDigits(i);
        for (auto c : digits) {
            if (i-c >= 0) {
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }

    cout << value[n] << endl;
    
    return 0;
}