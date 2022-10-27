#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<ll> x,a;
int n;
ll sumA=0, sumX=0, diff = 1000000000, calls = 0;
 
void search(int k) {
    calls++;

    diff = min(diff, abs(sumA-sumX));

    if (k == n+1) {
        return;
    } else {
        sumA += x[k];
        sumX -= x[k];
        search(k+1);
        sumA -= x[k];
        sumX += x[k];
        search(k+1);
    }
}
 
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll aux;
        cin >> aux;
        sumX += aux;
        x.push_back(aux);
    }
 
    search(0);

    cout << diff << endl;
}