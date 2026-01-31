// abc438 B - Substring 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;


//部分文字列をとる
//一番コストが低いのを出力
//コストはSi > Tiの時は Si - Ti;
//Si < Tiのときは Si + 9 - Ti + 1;

int main() {
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  int ans = 1000000000;
  for (int i = 0; i < n - m + 1; i++){
    string sub = s.substr(i, m);
    int cost = 0;
    for (int j = 0; j < m; j++){
      int si = sub[j] - '0';
      int ti = t[j] - '0';
      if (si > ti)
        cost += si - ti;
      else if (si < ti)
        cost += (si + 9) - ti + 1;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}
