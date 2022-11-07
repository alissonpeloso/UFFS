#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n, x, ct = 0, start, end;
    cin >> n >> x;

    vector<ll> p;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        p.push_back(a);
    }

    sort(p.rbegin(), p.rend());
    start = 0;
    end = n - 1;

    if(start > x) {
        start = lower_bound(p.begin(), p.end(), x) - p.begin();
    }

    while (start <= end)
    {
        if (p[start] + p[start+1] <= x)
        {
            ct++;
            start+=2;
        } else {
            vector<ll>::iterator tt = lower_bound(p.begin()+start, p.begin()+end, x-p[start], greater<ll>());

            if(*tt+p[start] <= x) {
                p.erase(tt);
                end--;
            }
            
            ct++;
            start++;
        }

    }

    cout << ct << endl;
}