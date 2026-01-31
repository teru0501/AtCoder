// tessoku-book A51 - Stack
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
  stack<string> st;
  while(q--){
    int flg;
    cin >> flg;
    if (flg == 1){
      string x;
      cin >> x;
      st.push(x);
    }
    else if (flg == 2){
      string ans = st.top();
      cout << ans << endl;
    }
    else{
      st.pop();
    }
  }
  return 0;
}
