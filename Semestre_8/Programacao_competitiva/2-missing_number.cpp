#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n;
    cin >> n;
 
    vector<int> v;
    for(int i = 1; i < n; i++){ 
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    sort(v.begin(), v.end());

    if(v[0] != 1) {cout << 1 << "\n"; return 0;}
    if(v[v.size()-1] != n) {cout << n << "\n"; return 0;}

    for(int i = 0; i < v.size()-1; i++){
        if(v[i+1] != v[i]+1){
            cout << v[i]+1 << "\n";
        }
    }
}

// int main() // Esse é bem mais rápido
// {
//     int n;
//     cin >> n;

//     int sumAll = 0;
//     for(int i = 1; i <= n; i++) sumAll+=i;

//     int sumIterator = 0;
//     for(int i = 1; i < n; i++){ 
//         int aux;
//         cin >> aux;
//         sumIterator+=aux;
//     }

//     cout << sumAll - sumIterator << "\n";
// }
