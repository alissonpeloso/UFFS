#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll sum = 0;
    vector<ll> v;
    for(ll i = 0; i < n ; i++){
        ll aux;
        cin >> aux;

        v.push_back(aux);
        if(i > 0){
            if(v[i] < v[i-1]){
                sum += v[i-1] - v[i];
                v[i] += v[i-1] - v[i];
            }
        }
    }

    cout << sum << "\n";
}