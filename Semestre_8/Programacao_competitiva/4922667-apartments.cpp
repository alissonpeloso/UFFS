#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n, m, k, cont = 0, x;
    cin>>n>>m>>k;
    vector<ll> a;
    vector<ll> b;

    for(ll i=0;i<n;i++) {
        cin>>x;
        a.push_back(x);
    }
 
    for(ll i=0;i<m; i++) {
        cin>>x;
        b.push_back(x);
    }
 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll startA = 0, startB = 0, endA = n-1, endB = m-1, index;

    vector<ll>::iterator it;

    while (startA <= endA) {
        index = lower_bound(b.begin()+startB, b.begin()+endB, a[startA]-k) - b.begin();
        if(b[index] >= a[startA]-k && b[index] <= a[startA]+k) {
            cont++;
            startB = index + 1;
        } else {
            startB = index;
        }

        startA++;
    }
 
    cout<<cont<<endl;
 
    return 0;
}