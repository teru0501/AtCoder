// joi2026yo1c D - 走り幅跳び (Long Jump)
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < n; i++){
    vector<int> a(m);
    for (auto &tmp : a)
      cin >> tmp;
    ans += *max_element(a.begin(), a.end());
  }
  cout << ans << endl;
}
