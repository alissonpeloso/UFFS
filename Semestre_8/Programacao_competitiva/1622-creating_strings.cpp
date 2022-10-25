#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
string a;
string permutation;
set<string> strings;
int n;
vector<bool> chosen; 
 
void search() {
    if (permutation.size() == n) {
        bool test = true;
        for(int i = 0; i < chosen.size(); i++) {
            test = test && chosen[i];
        }
        if(test) {
            strings.insert(permutation);
        }
        return;
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(a[i]);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
 
int main()
{
    cin >> a;
    n = a.size();
    for(int i = 0; i < n; i++) {
        chosen.push_back(false);
    }
 
    search();
 
    cout << strings.size() << endl;
 
    for (auto it = strings.begin(); it != strings.end(); ++it) {
        cout << *it << endl;
    }
}