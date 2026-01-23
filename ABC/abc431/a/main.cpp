// abc431 A - Robot Balance
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int h, b;
  cin >> h >> b;
  int ans = max(h - b, 0);
  cout << ans << endl;
  return 0;
}
