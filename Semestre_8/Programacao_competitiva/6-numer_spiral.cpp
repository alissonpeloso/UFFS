#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll getDiagonalNumber(ll n)
{
  ll sum = 1;
  ll pair = 2;
  for(ll i = 1; i < n; i++){
    sum+=pair;
    pair+=2;
  }

  return sum;
}

int main()
{
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    ll a, b;
    cin >> a >> b;

    if(a == b){
      cout << getDiagonalNumber(a) << "\n";
    } else {
      ll max = std::max(a, b);
      ll diagonal = getDiagonalNumber(max);
      ll result;

      if (max % 2 != 0){
        if (max == a) {
          result = diagonal - abs(a - b);
        } else {
          result = diagonal + abs(a - b);
        }
      } else {
        if (max == a) {
          result = diagonal + abs(a - b);
        } else {
          result = diagonal - abs(a - b);
        }
      }

      cout << result << "\n";
    }
  }
}