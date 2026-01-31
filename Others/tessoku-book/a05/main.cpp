// tessoku-book A05 - Three Cards
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      int cur = k - i - j;
      if (cur >= 1 && cur <= n){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
