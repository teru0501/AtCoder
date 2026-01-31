// tessoku-book B07 - Convenience Store 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//0 ~ t-1までの累積和をとる
//l ~ r - 1

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int t, n;
  cin >> t >> n;
  vector<int> sum(t, 0);
  while (n--){
    int l, r;
    cin >> l >> r;
    sum[l]++;
    sum[r]--;
  }
  cout << sum[0] << endl;
  for (int i = 1; i < t; i++){
    sum[i] += sum[i - 1];
    cout << sum[i] << endl;
  }
  return 0;
}
