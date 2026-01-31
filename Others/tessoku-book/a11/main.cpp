// tessoku-book A11 - Binary Search 1
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &tmp : a){
    cin >> tmp;
  }
  auto ans = lower_bound(a.begin(), a.end(), x) - a.begin();
  cout << ans + 1 << endl;
  return 0;
}
