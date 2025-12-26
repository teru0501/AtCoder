// abc437 B - Tombola
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> a(h, vector<int>(w));
  vector<int> call(h, 0);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  for (int i = 0; i < n; i++){
    int b;
    cin >> b;
    for (int j = 0; j < h; j++)
      for (int k = 0; k < w; k++)
        if (a[j][k] == b)
          call[j]++;
  }
  int ans = *max_element(call.begin(), call.end());
  cout << ans << endl;
}
