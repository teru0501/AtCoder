// abc433 A - Happy Birthday! 4
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int n = 10000;
  for (int i = 0; i <= n; i++){
    if (x + i == (y + i) * z){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
