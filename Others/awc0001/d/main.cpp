// awc0001 D - Merchant on the Highway
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

// DP?
// ナップサック
// dp[i][j] i番目まで見て、j円以下となるようにしたときの最大の利益
// mx[i][j] 直近に寄った町

void solve () {
  ll n, m, k;
  cin >> n >> m >> k;

  vl a(n);
  vl b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
  }
  ll dp[n + 1][m + 5];
  vvl vis(n + 1, vl(m + 1, -1));
  rep(i, m + 1) dp[0][i] = 0;

  loop(i, 1, n) {
    loop(j, 0, m) {
      dp[i][j] = 0;
      ll tmp1 = -1;
      ll tmp2 = dp[i - 1][j];
      // この街を通る
      if (j >= b[i - 1]) {
        if (vis[i - 1][j - b[i - 1]] == -1 || abs(i - vis[i - 1][j - b[i - 1]]) <= k) {
          tmp1 = dp[i - 1][j - b[i - 1]] + a[i - 1];
        }
      }
      if (tmp1 >= tmp2) {
        vis[i][j] = i;
        dp[i][j] = tmp1;
      }
      else {
        dp[i][j] = tmp2;
        vis[i][j] = vis[i - 1][j];
      }
    }

  }
  ll ans = 0;
  loop(i, 0, n) {
    loop(j, 0, m) {
      chmax(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
