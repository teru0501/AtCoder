// tessoku-book A04 - Binary Representation 1
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int n;
  cin >> n;
  string ans = "0000000000";
  for (int i = 0; i < 10; i++){
    ans[i] = (n % 2) + '0';
    n /= 2;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
