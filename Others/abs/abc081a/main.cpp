// abs ABC081A - Placing Marbles
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < 3; i++){
    if (s[i] == '1')
      ans++;
  }
  cout << ans << endl;
}
