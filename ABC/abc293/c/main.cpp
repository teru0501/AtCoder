// abc293 C - Make Takahashi Happy 
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

// DFS
// set参照

vvl g;
vector<vector<bool>> vis;
ll ans = 0;
unordered_set<ll> st;
ll h, w;

void dfs(ll x, ll y) {
  vis[x][y] = 1;
  st.insert(g[x][y]);
  // ゴール確認
  if (x == h - 1 && y == w - 1) {
    ans++;
    vis[x][y] = 0;
    st.erase(g[x][y]);
    return;
  }
  // 右
  if (in_grid(x, y + 1, h, w)) {
    if (!vis[x][y + 1] && !st.count(g[x][y + 1])) {
      dfs(x, y + 1);
    }
  }
  // 下
  if (in_grid(x + 1, y, h, w)) {
    if (!vis[x + 1][y] && !st.count(g[x + 1][y])) {
      dfs(x + 1, y);
    }
  }
  vis[x][y] = 0;
  st.erase(g[x][y]);
}

void solve () {
  cin >> h >> w;
  g.resize(h, vl(w));
  vis.assign(h, vector<bool>(w, 0));
  rep(i, h) rep(j, w) cin >> g[i][j];
  dfs(0, 0);
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
