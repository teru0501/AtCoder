// abs ABC086C - Traveling
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  int n_t = 0, n_x = 0, n_y = 0;
  for (int i = 0; i < n; i++){
    int t, x, y;
    cin >> t >> x >> y;
    int l = abs(x - n_x) + abs(y - n_y);
    int d = t - n_t;
    if (l <= d && abs(d - l) % 2 == 0){
      n_t = t;
      n_x = x;
      n_y = y;
    }
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
