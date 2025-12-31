// tessoku-book A15 - Compression
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1, {0, 0});
  vector<ll> ans(n + 1, 0);
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    a[i] = {tmp, i};
  }
  sort(a.begin(), a.end());
  for(int i = 1; i <= n; i++) {
    if (a[i].first != a[i - 1].first) {
      cnt++;
    }
    ans[a[i].second] = cnt;
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
