// abs ABC083B - Some Sums
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int sum_digits (int a){
  string s = to_string(a);
  int ans = 0;
  for (auto tmp : s)
    ans += (tmp - '0');
  return ans;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    int sum = sum_digits(i);
    if (sum >= a && sum <= b)
      ans += i;
  }
  cout << ans << endl;
}
