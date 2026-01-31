// abc435 B - No-Divisible Range
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> sum(n + 1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  
  for (int l = 1; l <= n; l++)
    for (int r = l; r <= n; r++){
      int num = sum[r] - sum[l - 1];
      bool flg = 1;
      for (int i = l; i <= r; i++){
        if (num % a[i] == 0)
          flg = 0;
      }
      if (flg) 
        ans++;
    }

  cout << ans << endl;
}
