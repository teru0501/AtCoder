// abc430 C - Truck Driver
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//累積和
//O(N * N)になりオバフロ
//二分探索でぎりぎりのところを探す

using ll = long long;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  ll n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  vector<ll> a_sum(n + 1, 0);
  vector<ll> b_sum(n + 1, 0);
  for (int i = 1; i <= n; i++){
    a_sum[i] += s[i - 1] == 'a' ? 1 : 0;
    a_sum[i] += a_sum[i - 1];
    b_sum[i] += s[i - 1] == 'b' ? 1 : 0;
    b_sum[i] += b_sum[i - 1];
  }

  int prev = 1;
   int l = 1, r = 1;
  
  for (int i = 1; i <= n; i++){
    while (r <= n && a_sum[r] - a_sum[i - 1] >= a) r++;
  }
  return 0;
}
