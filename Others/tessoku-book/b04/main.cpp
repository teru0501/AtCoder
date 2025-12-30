// tessoku-book B04 - Binary Representation 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

long long power(long long base, long long expo) {
  long long res = 1;
  while (expo > 0) {
    if (expo & 1) res *= base;
      base *= base;
      expo >>= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  string n;
  cin >> n;
  long long ans = 0;
  reverse(n.begin(), n.end());
  for (int i = 0; i < n.length(); i++){
    ans += power(2, i) * (n[i] - '0');
  }
  cout << ans << endl;
  return 0;
}
