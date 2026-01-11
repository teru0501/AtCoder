// dp C - Vacation
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
// それぞれを選んだ場合の最大値
// ============================================ //

void solve () {
  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  rep0 (i, n) {
    cin >> a[i] >> b[i] >> c[i];
  }
  int dp[100010][3];
  rep0 (i, 100010) {
    dp[i][0] = -1;
    dp[i][1] = -1;
    dp[i][2] = -1;
  }
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  for (int i = 1; i < n; i++) {
    // A 
    chmax(dp[i][0], dp[i - 1][1] + a[i]);
    chmax(dp[i][0], dp[i - 1][2] + a[i]);
    // B 
    chmax(dp[i][1], dp[i - 1][0] + b[i]);
    chmax(dp[i][1], dp[i - 1][2] + b[i]);
    // C
    chmax(dp[i][2], dp[i - 1][0] + c[i]);
    chmax(dp[i][2], dp[i - 1][1] + c[i]);
  }
  OUT(max(dp[n - 1][2], max(dp[n - 1][0], dp[n - 1][1])));
  return;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  solve();
  return 0;
}
