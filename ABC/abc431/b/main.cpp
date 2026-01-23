// abc431 B - Robot Weight
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//三項演算子 ? : を理解

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int x, n;
  cin >> x >> n;
  vector<int> w(n + 1, 0);
  vector<bool> on(n + 1, 0);
  for (int i = 1; i <= n; i++){
    cin >> w[i];
  }
  int q;
  cin >> q;
  while (q--){
    int p;
    cin >> p;
    x += on[p] ? -w[p] : w[p];
    on[p] = !on[p];
    cout << x << endl;
  }
  return 0;
}
