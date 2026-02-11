// abc270 C - Simple path
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

ll n, x, y;
vvl g;
vector<bool> vis;
deque<ll> dq;

// DFS
void dfs(ll v) {

  if (v == y) {
    ll sz = dq.size();
    rep(i, sz) {
      if (i) cout << " ";
      cout << dq[i];
    }
    cout << endl;
    return;
  }
  vis[v] = 1;
  for (auto to : g[v]) {
    if (!vis[to]) {
      dq.push_back(to);
      dfs(to);
      dq.pop_back();
    }
  }
  vis[v] = 0;
}
void solve () {
  cin >> n >> x >> y;
  g.resize(n + 1);
  vis.assign(n + 1, 0);

  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dq.push_back(x);
  dfs(x);
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
