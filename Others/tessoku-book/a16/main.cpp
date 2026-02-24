// tessoku-book A16 - Dungeon 1（※初版第 1 刷の B22 も同じ問題です）
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
  vl a(n + 1, 0);
  vl b(n + 1, 0);
  loop(i, 2, n) cin >> a[i];
  loop(i, 3, n) cin >> b[i];

  ll dp[n + 1]; 
  loop(i, 1, n) dp[i] = INF;
  dp[1] = 0;
  // 部屋1から部屋nまで行くのにかかる最短時間

  loop(i, 1, n - 1) {
    chmin(dp[i + 1], dp[i] + a[i + 1]);
    if (i != n - 1) {
      chmin(dp[i + 2], dp[i] + b[i + 2]);
    }
  }
    
  cout << dp[n] << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
