// dp A - Frog 1
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define IN(v) for (auto &x : (v)) cin >> x;
#define OUT(x) cout << (x) << endl
#define VOUT(v) do { for(auto x : (v)) cout << x << " "; cout << endl; } while(0)
#define VVOUT(vv) do { for(auto &v : (vv)) VOUT(v); } while(0)
#define rep0(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

// ================= CONST ================= //
const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dy = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0 <= i && i < h && 0 <= j && j < w);}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

// ================= STRATEGY ================= //
// 制約をみろ！！
// 愚直を考えろ！！
// オバフロ注意！！
// ============================================ //

/*
void solve () {
  int n;
  cin >> n;
  vi h(n);
  IN(h);
  int dp[n + 5];
  rep0 (i, n + 5) {
    dp[i] = INF;
  }
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    if (i != 1)
      chmin(dp[i], abs(h[i] - h[i - 2]) + dp[i - 2]);
    chmin(dp[i], abs(h[i] - h[i - 1]) + dp[i - 1]);
  }
  OUT(dp[n - 1]);
  return;
}
*/

vll h(10005);
vll dp(10005, LINF);

ll rec (int i) {
  if (dp[i] != LINF) return dp[i];
  if (i == 0) return 0;
  ll res = LINF;
  chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));
  if (i > 1) chmin(res, rec( i- 2) + abs(h[i] - h[i - 2]));
  return dp[i] = res;
}

void solve () {
  int n;
  cin >> n;
  rep0 (i, n) {
    cin >> h[i];
  }
  OUT(rec(n - 1));
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  solve();
  return 0;
}
