// abs ABC081B - Shift only
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  for (auto &tmp : a)
    cin >> tmp;

  while (true){
    int flg = 1;

    for (auto tmp : a){
      if (tmp % 2 == 1){
        flg = 0;
      }
    }
    
    if (flg){
      for (auto &tmp : a)
        tmp /= 2;
      ans++;
    }
    else
      break;
  }
  
  cout << ans << endl;
}
