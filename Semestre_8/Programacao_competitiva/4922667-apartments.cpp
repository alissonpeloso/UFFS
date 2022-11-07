#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n, m, k, cont = 0;
    cin>>n>>m>>k;
    ll a[n];
    ll b[m];
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
 
    for(ll i=0;i<m; i++) {
        cin>>b[i];
    }
 
    sort(a,a+n);
    sort(b,b+m);   
 
    vector<ll> search_vector(b,b+m);

    vector<ll>::iterator it = upper_bound(search_vector.begin(), search_vector.end(), b[m-1]+k);
    search_vector = vector<ll>(search_vector.begin(), it);

    for(auto i:a) {
        it = lower_bound(search_vector.begin(), search_vector.end(), i-k);
        if(*it <= i+k ) {
            cont++;
            it++;
            search_vector = vector<ll>(it, search_vector.end());
        } else {
            search_vector = vector<ll>(it, search_vector.end());
        }
    }
 
    cout<<cont<<endl;
 
    return 0;
}