// abc429 A - Too Many Requests
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
  for (int i = 1; i <= n; i++){
    if (i <= m) cout << "OK";
    else cout << "Too Many Requests";
    cout << endl;
  }
  return 0;
}
