#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<ll> v;
    for(int i = 1; i <= n; i++){ 
        v.push_back(i);
    }


    for(int i = 1; i < n; i++){
        ll input;
        cin >> input;
        remove(v.begin(), v.end(), input);
    }

    cout << v[0] << "\n";

}