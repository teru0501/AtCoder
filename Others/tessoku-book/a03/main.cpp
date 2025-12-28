// tessoku-book A03 - Two Cards
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<int> q(n);
  for (auto &tmp : p){
    cin >> tmp;
  }
  for (auto &tmp : q){
    cin >> tmp;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (p[i] + q[j] == k){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
