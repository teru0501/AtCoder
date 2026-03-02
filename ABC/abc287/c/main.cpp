// abc287 C - Path Graph?
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

vvl g;
vector<bool> vis;
bool f = 1;

void dfs(ll v, ll pre) {
  vis[v] = 1;
  if (g[v].size() > 2) {
    f = 0;
    return;
  }
  for (auto to : g[v]) {
    if (!vis[to]) dfs(to, v);
    else if (to != pre) f = 0;
  }
}

void solve () {
  ll n, m;
  cin >> n >> m;

  g.resize(n + 1);
  vis.assign(n + 1, 0);

  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, -1);

  loop(i, 1, n) {
    if (!vis[i]) f = 0;
  }

  if (f) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
