// tessoku-book A55 - Set
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
  set<int> st;
  while (q--){
    int f;
    cin >> f;
    if (f == 1){
      int x;
      cin >> x;
      st.insert(x);
    }
    else if (f == 2){
      int x;
      cin >> x;
      st.erase(x);
    }
    else {
      int x;
      cin >> x;
      auto it = st.lower_bound(x);
      if (it == st.end()){
        cout << -1 << endl;
      }
      else {
        int ans = *it;
        cout << ans << endl;
      }
    }
  }
  return 0;
}
