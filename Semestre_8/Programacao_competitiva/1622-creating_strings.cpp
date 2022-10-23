#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void search() {
    if (permutation.size() == n) {
        // process permutation
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
 
int main()
{
    string a;
    cin >> a;


}