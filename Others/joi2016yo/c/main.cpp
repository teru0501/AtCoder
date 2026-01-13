// joi2016yo C - ロシアの旗 (Russian Flag)
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
// 累積和を使う
// wsum, bsum, rsum
// 全てのパターンを全探索
// i : 白の一番下
// j : 青と一番下
// ============================================ //

void solve () {
  int n, m;
  cin >> n >> m;
  vi w_sum(n + 1, 0);
  vi b_sum(n + 1, 0);
  vi r_sum(n + 1, 0);
  // 累積和
  rep1 (i, n) {
    string s;
    cin >> s;
    for (auto tmp : s) {
      if (tmp == 'W') w_sum[i]++;
      else if (tmp == 'B') b_sum[i]++;
      else r_sum[i]++;
    }
  }
  rep1 (i, n) {
    w_sum[i] += w_sum[i - 1];
    b_sum[i] += b_sum[i - 1];
    r_sum[i] += r_sum[i - 1];
  }
  int ans = INF;
  // 全探索
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      int sum = 0;
      // 白
      sum += i * m - (w_sum[i] - w_sum[0]);
      // 青
      sum += (j - i) * m - (b_sum[j] - b_sum[i]);
      // 赤
      sum += (n - j) * m - (r_sum[n] - r_sum[j]);

      ans = min(ans, sum);
    }
  }
  OUT(ans);
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
