// joi2025yo2 A - マスキングテープ (Masking Tape)
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
// 覆われているか、そのマスの色はなにかを管理する
// ============================================ //

void solve () {
  int h, w, q;
  cin >> h >> w >> q;
  vvi color(h + 1, vi(w + 1, 0));
  vector<vector<bool>> covered(h + 1, vector<bool>(w + 1, 0));
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y, c;
      cin >> x >> y >> c;
      if (!covered[x][y]) color[x][y] = c;
      if (!covered[x + 1][y]) color[x + 1][y] = c;
      if (!covered[x][y + 1]) color[x][y + 1] = c;
      if (!covered[x + 1][y + 1]) color[x + 1][y + 1] = c;
    }
    else {
      int x, y;
      cin >> x >> y;  
      covered[x][y] = 1;
      covered[x + 1][y] = 1;
      covered[x][y + 1] = 1;
      covered[x + 1][y + 1] = 1;
    }
  }
  // 出力
  rep1 (i, h) {
    rep1 (j, w) {
      if (j != 1) cout << " ";
      cout << color[i][j];
    }
    cout << endl;
  }
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
