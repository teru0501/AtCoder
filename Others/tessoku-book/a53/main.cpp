// tessoku-book A53 - Priority Queue
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
  priority_queue<int, vector<int>, greater<int>> pq;
  while (q--){
    int flg;
    cin >> flg;
    if (flg == 1){
      int x;
      cin >> x;
      pq.push(x);
    }
    else if (flg == 2){
      int ans = pq.top();
      cout << ans << endl;
    }
    else{
      pq.pop();
    }
  }
  return 0;
}
