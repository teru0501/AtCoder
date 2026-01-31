// abs ABC085B - Kagami Mochi
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  int ans = s.size();
  cout << ans << endl;
}
