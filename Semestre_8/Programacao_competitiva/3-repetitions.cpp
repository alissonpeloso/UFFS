#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main()
{
    string str;
    cin >> str;

    int sum = 1;
    int aux = 1;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == str[i+1]) aux++;
        else aux = 1;
        if(aux > sum) sum = aux;
    }

    cout << sum << "\n";
}