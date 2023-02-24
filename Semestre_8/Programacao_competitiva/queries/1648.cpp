#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, q;
vector<ll> tree, v;

ll sum(ll k) {
    ll s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(ll k, ll x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

ll p(ll k){
    return k & -k;
}

void create_tree() {
    for (ll i = 1; i <= n; i++) {
        ll aux = 0;
        for (ll j = i-p(i)+1; j <= i; j++) {
            aux += v[j];
        }

        tree[i] = aux;
    }
}

int main()
{
    cin >> n >> q;

    v = vector<ll>(n+1);
    tree = vector<ll>(n+1);

    for(ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    create_tree();

    for(ll i = 1; i <= q; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            add(b, c-v[b]);
            v[b] = c;
        }
        else
        {
            cout << sum(c) - sum(b-1) << endl;
        }
    }
}