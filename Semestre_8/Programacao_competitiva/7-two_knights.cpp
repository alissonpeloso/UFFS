#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main()
{
  ll n;
  cin >> n;

  vector<ll> v = {4,1};

  for(ll i = 1; i <= n; i++) {
    if (i == 1){
      cout << 0 << "\n";
    } else if(i == 2){
      cout << 6 << "\n";
    } else if(i == 3){
      cout << 28 << "\n";
    } else if(i == 4){
      cout << 96 << "\n";
    } else {
      if(i % 2 != 0) {
        v.push_back(1);
      }

      ll result = 4*(pow(i, 2)-3) + 8 * (pow(i, 2)-4);

      for(ll j = 0; j < v.size(); j++) {
        if(i % 2 == 0 || j != v.size()-1){
          if(v[j] == 1) {
            v[j] = 4;
          } else {
            v[j] += 4;
          }
        }

        if (j == 0) {
          result += v[j] * (pow(i, 2)-5);
        } else if (j == 1) {
          result += v[j] * (pow(i, 2)-7);
        } else {
          result += v[j] * (pow(i, 2)-9);
        }
      }

      result /= 2;

      cout << result << "\n";
    }
  }
}