// abc433 B - Nearest Taller
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//全探索

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &tmp : a)
    cin >> tmp;
  cout << -1 << endl;
  for (int i = 1; i < n; i++){
    bool flg = 0;
    for (int j = i - 1; j >= 0; j--){
      if (a[i] < a[j]){
        cout << j + 1 << endl;
        flg = 1;
        break;
      }
    }
    if (!flg)
      cout << -1 << endl;
  }
}
