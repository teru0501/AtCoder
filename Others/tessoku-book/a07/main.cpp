// tessoku-book A07 - Event Attendance
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//いもす法
//indexミスをしないこと！

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int d, n;
  cin >> d >> n;
  vector<int> ans(d + 2, 0);
  for (int i = 0; i < n; i++){
    int l, r;
    cin >> l >> r;
    ans[l]++;
    ans[r + 1]--;
  }
  for (int i = 1; i <= d; i++){
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= d; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
