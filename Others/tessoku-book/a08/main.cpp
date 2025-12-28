// tessoku-book A08 - Two Dimensional Sum
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int h, w;
  cin >> h >> w;
  vector<vector<int>> sum(h + 1, vector<int>(w + 1, 0));
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      cin >> sum[i][j];
    }
  }
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      sum[i][j] += sum[i - 1][j];
    }
  }
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      sum[i][j] += sum[i][j - 1];
    }
  }
  int q;
  cin >> q;
  while(q--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = sum[c][d];
    ans -= sum[c][b - 1];
    ans -= sum[a - 1][d];
    ans += sum[a - 1][b - 1];
    cout << ans << endl;
  }
  return 0;
}
