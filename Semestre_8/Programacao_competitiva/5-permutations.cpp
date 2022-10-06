#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void print(vector<int> v)
{
  for (auto i: v) {
    cout << i << ' ';
  }

  cout << endl;
}

int main()
{
  int n;
  cin >> n;

  if(n == 1) {
    cout << "1" << "\n";
    return 0;
  } 

  if(n <= 3) {
    cout << "NO SOLUTION" << "\n";
    return 0;
  } 

  vector<int> even;
  vector<int> odd;
  for(int i = 1; i <= n; i++){
    if(i % 2 != 0){
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }

  vector<int> v;
  v.insert(v.begin(), even.begin(), even.end());
  v.insert(v.end(), odd.begin(), odd.end());

  bool right = true;

  for(int i = 0; i < v.size()-1; i++){
    if(abs(v[i] - v[i+1]) == 1) {
      right = false;
    }
  }
  
  if(right) {
    print(v);
    return 0;
  }
  cout << "NO SOLUTION" << "\n";
}