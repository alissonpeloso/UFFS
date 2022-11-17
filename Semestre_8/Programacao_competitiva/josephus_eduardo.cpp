#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
    int n;
    vector<int> v;

    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    ll k = 2, j;

    // Imprimindo os números pares
    for(ll i = 0; i < n; i++) {
        cout << k << " ";
        k = k+2;

        if(k > n) {
            break;
        }
    }

    if (n % 2 == 0) {
        j = 1;
    } else {
        j = 0;
    }

    for (int i = 0; i < n; i+=2) {
        v.push_back(i+1);
    }

    while(v.size() != 1) {
        cout << v[j] << " ";
        v.erase(v.begin()+j);
        j += 1;

        if (j >= v.size()) {
            j = j % v.size();
        }
    }

    cout << v[0] << endl; 
}