// abc266 D - Snuke Panic (1D)
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

// dp

void solve () {
  ll n;
  cin >> n;

  ll m = 0;
  ll now = 1;

  vl t(n + 1), x(n + 1), a(n + 1);

  loop(i, 1, n) {
    cin >> t[i] >> x[i] >> a[i];
    chmax(m, t[i]);
  }

  ll dp[m + 1][5];
  rep(i, 5) dp[0][i] = -INF;

  dp[0][0] = 0;

  loop(i, 1, m) {
    rep(j, 5) {
      dp[i][j] = dp[i - 1][j];
      if (now > n || i != t[now] || j != x[now]) continue;

      rep(k, 5) {
        ll c = max(abs(j - k), 1LL);
        if (i >= c) 
          chmax(dp[i][j], dp[i - c][k] + a[now]);
      }
      now++;
    }
  }

  ll ans = 0;
  rep(i, 5) chmax(ans, dp[m][i]);

  cout << ans << "\n";

  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
