// abc436 C - 2x2 Placing
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  unordered_set<string> s;
  while(m--){
    int r, c;
    cin >> r >> c;
    string a = to_string(r) + '/' + to_string(c);
    string b = to_string(r + 1) + '/' + to_string(c);
    string x = to_string(r) + '/' + to_string(c + 1);
    string y = to_string(r + 1) + '/' + to_string(c + 1);

    if (!s.count(a) && !s.count(b) && !s.count(x) && !s.count(y)){
      s.insert(a);
      s.insert(b);
      s.insert(x);
      s.insert(y);
      ans++;
    }
  }
  cout << ans << endl;
}
