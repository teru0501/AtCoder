// joi2026yo1c B - リンゴ (Apple)
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  int ans = x * (n % 2);
    ans += y * 2 * (n / 2);
  cout << ans << endl;
}
