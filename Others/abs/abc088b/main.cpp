// abs ABC088B - Card Game for Two
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  priority_queue<int> pq;
  int alice = 0, bob = 0;
  for (int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }
  for (int i = 0; i < n; i++){
    int num = pq.top();
    pq.pop();
    if (i % 2 == 0)
      alice += num;
    else
      bob += num;
  }
  int ans = alice - bob;
  cout << ans << endl;
}
