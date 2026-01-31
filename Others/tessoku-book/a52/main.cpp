// tessoku-book A52 - Queue
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
  queue<string> que;
  while(q--){
    int flg;
    cin >> flg;
    if (flg == 1){
      string x;
      cin >> x;
      que.push(x);
    }
    else if (flg == 2){
      string ans = que.front();
      cout << ans << endl;
    }
    else {
      que.pop();
    }
  }
  return 0;
}
