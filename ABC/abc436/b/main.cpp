// abc436 B - Magic Square
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  int cnt = 1;
  vector<vector<int>> ans(n, vector<int>(n, -1));
  ans[0][(n - 1) / 2] = cnt;
  cnt++;
  int r = 0, c = (n - 1) / 2;
  for (int i = 0; i < n * n - 1; i++){
    if (ans[((r - 1) + n) % n][((c + 1) + n) % n] == -1){
      r = ((r - 1) + n) % n;
      c = ((c + 1) + n) % n;
    }
    else{
      r = ((r + 1) + n) % n;
    }
    ans[r][c] = cnt;
    cnt++;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
}
