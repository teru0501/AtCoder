// abc432 A - Permute to Maximize
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  vector<int> v(3);
  for (auto &tmp : v){
    cin >> tmp;
  }
  sort(v.begin(), v.end());
  int ans = v[2] * 100 + v[1] * 10 + v[0];
  cout << ans << endl;
  return 0;
}
