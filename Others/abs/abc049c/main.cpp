// abs ABC049C - Daydream
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  string s;
  cin >> s;
  while (!s.empty()){
    bool flg = 0;
    if (s.length() >= 5)
      {
        string sub5 = s.substr(s.length() - 5, s.length());
        if (sub5 == "dream" || sub5 == "erase"){
          s.erase(s.length() - 5, s.length());
          flg = 1;
        }
      }
    if (s.length() >= 6 && !flg)
      {
        string sub6 = s.substr(s.length() - 6, s.length());
        if (sub6 == "eraser"){
          s.erase(s.length() - 6, s.length());
          flg = 1;
        }
      }
    if (s.length() >= 7&& !flg)
      {
        string sub7 = s.substr(s.length() - 7, s.length());
        if (sub7 == "dreamer"){
          s.erase(s.length() - 7, s.length());
          flg = 1;
        }
      }
    if (!flg){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
