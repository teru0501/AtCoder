// abc429 C - Odd One Subsequence
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//ハッシュ

using ll = long long;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  ll n;
  cin >> n;
  unordered_map<ll, ll> um;
  ll sum = 0;
  ll ans = 0;
  for (ll i = 0; i < n; i++){
    ll tmp;
    cin >> tmp;
    um[tmp]++;
    sum++;
  }
  for (auto [x, y] : um){
    if (y >= 2){
      ll num = (y * (y - 1)) / 2;
      ans += num * (sum - y);
    }
  }
  cout << ans << endl;
  return 0;
}
