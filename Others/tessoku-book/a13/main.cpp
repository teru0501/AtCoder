// tessoku-book A13 - Close Pairs
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

//左から差

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll ans = 0;
  
  for (auto &tmp : a){
    cin >> tmp;
  }
  for (int i = 0; i < n; i++){
    ll need = k + a[i];
    ll it = upper_bound(a.begin() + i, a.end(), need) - a.begin();
    ans += it - i - 1;
  }
  cout << ans << endl;
  return 0;
}
