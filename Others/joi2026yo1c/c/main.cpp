// joi2026yo1c C - ビルディング 5 (Building 5)
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n);
  int ans = 0;
  for (auto &tmp : h){
    cin >> tmp;
    if (tmp >= x)
      ans++;
  }
  cout << ans << endl;
}
