// abc434 D - Clouds
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

//  マスの総数 - すべての雲のマス - その雲しかかかっていないマス

int main() {
  ll n;
  cin >> n;
  vector<vector<ll>> kind(2025, vector<ll>(2025, 0));
  vector<vector<ll>> sum(2025, vector<ll>(2025, 0));
  for (ll i = 1; i <= n; i++){
    ll u, d, l, r;
    cin >> u >> d >> l >> r;
    d++; r++;
    kind[u][l]++;
    kind[u][r]--;
    kind[d][l]--;
    kind[d][r]++;
    sum[u][l] += i;
    sum[u][r] -= i;
    sum[d][l] -= i;
    sum[d][r] += i;
  }

  for (ll i = 1; i < 2025; i++)
    for (ll j = 1; j < 2025; j++)
      if (j){
        kind[i][j] += kind[i][j - 1];
        sum[i][j] += sum[i][j - 1];
      }

  for (ll i = 1; i < 2025; i++)
    for (ll j = 1; j < 2025; j++)
      if (i){
        kind[i][j] += kind[i - 1][j];
        sum[i][j] += sum[i - 1][j];
      }

  vector<ll> ans(n + 1, 0);
  ll amount = 0;
  for (ll i = 1; i <= 2000; i++)
    for (ll j = 1; j <= 2000; j++){
      if (kind[i][j] == 1)
        ans[sum[i][j]]++;
      if (kind[i][j] != 0)
        amount++;
    }
  for (ll i = 1; i <= n; i++)
      cout << 2000 * 2000 - amount + ans[i] << endl;
}

