// abc429 B - N - 1
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (auto &tmp : a){
    cin >> tmp;
    sum += tmp;
  }
  for (int i = 0; i < n; i++){
    if (sum - a[i] == m){
      cout << "Yes" << endl;
      return 0;
     }
  }
  cout << "No" << endl;
  return 0;
}
