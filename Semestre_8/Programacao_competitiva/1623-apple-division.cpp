#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<ll> x;
int n;
ll sumA=0, sumB=0, sumX=0, diff = 1000000000;
 
void search() {
    if (x.size() == 0) {
        if(abs(sumA - sumB) < diff) {
            diff = abs(sumA - sumB);
        }
        return;
    } else {
        for (int i = 0; i < x.size(); i++) {
            ll val = x[i];

            sumA += val;
            sumX -= val;
            x.erase(x.begin() + i);
            search();

            sumA -= val;
            sumB += val;
            search();

            x.insert(x.begin() + i, val);
            sumB -= val;
            sumX += val;
        }
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
 
    search();

    cout << diff << endl;
}