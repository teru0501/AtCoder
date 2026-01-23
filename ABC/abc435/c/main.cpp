// abc435 C - Domino
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  ll m = a[1];
  for (int i = 1; i <= m; i++){
    m = max(m, a[i] + i - 1);
    m = min(m, n);
  }
  cout << m << endl;
}
