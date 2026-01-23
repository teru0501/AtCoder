// joi2009yo D - 薄氷渡り
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
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
// 全通り試す
// ============================================ //

vvi g;
vector<vector<bool>> vis;
int h, w;
ll ans = 0;

void dfs (ll x, ll y, ll m) {
  m++;
  ans = max(m, ans);
  vis[x][y] = 1;
  rep0 (i, 4) {
    ll to_x = x + dx[i];
    ll to_y = y + dy[i];
    if (in_grid(to_x, to_y, h, w)) {
      if (!vis[to_x][to_y] && g[to_x][to_y] == 1) {
        dfs(to_x, to_y, m);
      }
    }
  }

  vis[x][y] = 0;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  cin >> w >> h;
  g.assign(h, vi(w));
  vis.assign(h, vector<bool>(w, 0));
  rep0 (i, h) {
    rep0 (j, w) {
      cin >> g[i][j];
    }
  }
  rep0 (i, h) {
    rep0 (j, w) {
      if (g[i][j] == 1) {
        int m = 0;
        dfs(i, j, m);
      }
    }
  }
  OUT(ans);
  return 0;
}
