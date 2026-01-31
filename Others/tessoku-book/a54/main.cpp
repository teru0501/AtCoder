// tessoku-book A54 - Map
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int q;
  cin >> q;
  unordered_map<string, int> um;
  while(q--){
    int f;
    cin >> f;
    if (f == 1){
      string x;
      int y;
      cin >> x >> y;
      um[x] = y;
    }
    else {
      string x;
      cin >> x;
      int ans = um[x];
      cout << ans << endl;
    }
  }
  return 0;
}
