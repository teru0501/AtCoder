// abc434 A - Balloon Trip
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int w, b;
  cin >> w >> b;
  w *= 1000;
  int ans = (w / b) + 1;
  cout << ans << endl;
}
