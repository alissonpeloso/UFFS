#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> digits = {1, 2, 3, 4, 5, 6};
vector<ll> value;
ll m = pow(10, 9) + 7;

int main()
{
    ll x;
    cin >> x;

    value.reserve(x+1);

    value[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto c : digits) {
            if (i-c >= 0) {
                value[i] += value[i-c];
                value[i] %= m;
            }
        }
    }

    cout << value[x] << endl;
}