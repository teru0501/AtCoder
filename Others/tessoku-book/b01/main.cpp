// tessoku-book B01 - A+B Problem
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define ANS() do { cout << ans << endl; } while (0)

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int a, b;
  cin >> a >> b;
  int ans = a + b;
  ANS();
  return 0;
}
