// abc430 B - Count Subgrid
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &tmp : s){
    cin >> tmp;
  }
  unordered_set<string> st;
  for (int i = 0; i < n - m + 1; i++){
    for (int j = 0; j < n - m + 1; j++){
      string sub;
      for (int k = 0; k < m; k++){
        sub += s[i + k].substr(j, m);
      }
      st.insert(sub);
    }
  }
  int ans = st.size();
  cout << ans << endl;
  return 0;
}
