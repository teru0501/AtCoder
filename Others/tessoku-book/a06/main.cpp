// tessoku-book A06 - How Many Guests?
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, q;
  cin >> n >> q;
  vector<int> sum(n + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; i++){
    int a;
    cin >> a;
    sum[i] = sum[i - 1] + a;
  }
  while(q--){
    int l, r;
    cin >> l >> r;
    int ans = sum[r] - sum[l - 1];
    cout << ans << endl;
  }
  return 0;
}
