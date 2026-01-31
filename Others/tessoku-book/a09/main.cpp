// tessoku-book A09 - Winter in ALGO Kingdom
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> ans(h + 2, vector<int>(w + 2, 0));
  while(n--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ans[a][b]++;
    ans[a][d + 1]--;
    ans[c + 1][b]--;
    ans[c + 1][d + 1]++;
  }
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      ans[i][j] += ans[i][j - 1];
    }
  }
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      ans[i][j] += ans[i - 1][j];
    }
  }
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      if (j != 1)
        cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
