// tessoku-book A21 - Block Game
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lower(v, x) lower_bound(all(v), x)
#define upper(v, x) upper_bound(all(v), x)
#define rep(i,n) for (ll i=0;i<(ll)n;i++)
#define rrep(i,n) for (ll i=(n)-1;i>=(ll)0;i--)
#define loop(i,m,n) for(ll i=m;i<=(ll)n;i++)
#define rloop(i,m,n) for(ll i=m;i>=(ll)n;i--)

// ================= CONST ================= //
const vl dx = {-1,0,1,0};
const vl dy = {0,1,0,-1};
const vl dx8 = {-1,-1,-1,0,1,1,1,0};
const vl dy8 = {-1,0,1,1,1,0,-1,-1};
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

void solve () {
  ll n;
  cin >> n;
  vl p(n + 1, 0), a(n + 1, 0);

  loop(i, 1, n) cin >> p[i] >> a[i];

  ll dp[n + 1][n + 1];
  loop(i, 1, n) loop(j, 1, n) dp[i][j] = 0;
  // lからrが残っているときの最大スコア

  rloop(len, n, 1) {
    loop(l, 1, n - len + 1) {
      ll r = l + len - 1;
      ll s1 = 0;
      ll s2 = 0;
      // 左端を消した時のポイント
      if (l != 1 && l <= p[l - 1] && r >= p[l - 1]) {
        s1 = a[l - 1];
      }
      // 右端を消した時のポイント
      if (r != n && l <= p[r + 1] && r >= p[r + 1]) {
        s2 = a[r + 1];
      }

      // 最大スコアを計算
      if (l == 1) chmax(dp[l][r], dp[l][r + 1] + s2);
      else if (r == n) chmax(dp[l][r],dp[l - 1][r] + s1);
      else {
        chmax(dp[l][r],dp[l - 1][r] + s1);
        chmax(dp[l][r], dp[l][r + 1] + s2);
      }
    }
  }

  ll ans = 0;
  loop(i, 1, n) {
    chmax(ans, dp[i][i]);
  }

  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
