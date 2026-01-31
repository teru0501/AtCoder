// abs ABC085C - Otoshidama
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n - i; j++){
         ll sum = 10000 * i + 5000 * j + 1000 * (n - i - j);
        if (sum == y){
          cout << i << " " << j << " " << (n - i - j) << endl;
          return 0;
        }
    }
  cout << -1 << " " << -1 << " " << -1 << endl;
}
