// tessoku-book A10 - Resort Hotel
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//左から右、右から左の累積maxを求める！

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  vector<int> left(n + 2, 0);
  vector<int> right(n + 2, 0);

  for (int i = 1; i <= n; i++){
    left[i] = max(left[i - 1], a[i]);
  }
  for (int i = n; i >= 1; i--){
    right[i] = max(right[i + 1], a[i]);
  }
  int d;
  cin >> d;
  while (d--){
    int l, r;
    cin >> l >> r;
    int ans = max(left[l - 1], right[r + 1]);
    cout << ans << endl;
  }
  return 0;
}
