// tessoku-book B06 - Lottery
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//アタリとハズレの累積和をとる

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vector<int> o_sum(n + 1, 0);
  vector<int> x_sum(n + 1, 0);
  for (int i = 1; i <= n; i++){
    bool tmp;
    cin >> tmp;
    o_sum[i] += tmp ? 1 : 0;
    x_sum[i] += !tmp ? 1 : 0;
    o_sum[i] += o_sum[i - 1];
    x_sum[i] += x_sum[i - 1];
  }
  int q;
  cin >> q;
  while (q--){
    int l, r;
    cin >> l >> r;
    int o = o_sum[r] - o_sum[l - 1];
    int x = x_sum[r] - x_sum[l - 1];
    if (o > x)  cout << "win" << endl;
    else if (o < x) cout << "lose" << endl;
    else cout << "draw" << endl;
  }
  return 0;
}
