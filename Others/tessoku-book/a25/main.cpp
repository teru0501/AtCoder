// tessoku-book A25 - Number of Routes
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
#define rep(i,n) for (ll i=0;i<(ll)n;i++)
#define rrep(i,n) for (ll i=(n)-1;i>=(ll)0;i--)
#define loop(i,m,n) for(ll i=m;i<=(ll)n;i++)
#define rloop(i,m,n) for(ll i=m;i>=(ll)n;i--)

// ================= CONST ================= //
const vl dx = {-1,0,1,0};
const vl dy = {0,1,0,-1};
//const vl dx = {-1,-1,-1,0,1,1,1,0};
//const vl dy = {-1,0,1,1,1,0,-1,-1};
const ll INF = 4e18;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

// dp[i][j] マスi, jまで行ったとき、何通りあるか？

void solve () {
  ll h, w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i, h) cin >> g[i];
  
  ll dp[h][w];
  dp[0][0] = 1;
  rep(i, h) {
    rep(j, w) {
      if (i == 0 && j == 0) continue;
      dp[i][j] = 0;
      if (g[i][j] == '#') continue;
      // 上からの遷移
      if (i != 0) dp[i][j] += dp[i - 1][j];
      // 左からの遷移
      if (j != 0) dp[i][j] += dp[i][j - 1];
    }
  }
  cout << dp[h - 1][w - 1] << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
