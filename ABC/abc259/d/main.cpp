// abc259 D - Circumferences
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
bool f = 0;

ll euclid(ll x1, ll y1, ll x2, ll y2) {
    ll a = x1 - x2;
    ll b = y1 - y2;
    return a * a + b * b;
}

void dfs(ll v, ll t) {
  if (f) return;
  vis[v] = 1;
  if (v == t) {
    cout << "Yes" << "\n";
    f = 1;
    return;
  }
  for (auto to : g[v]) {
    if (f) return;
    if (!vis[to]) dfs(to, t);
  }
}

void solve () {
  ll n;
  cin >> n;
  
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  ll s = -1, t = -1;

  g.resize(n);
  vis.assign(n, 0);

  vl x(n), y(n), r(n);
  rep(i, n) cin >> x[i] >> y[i] >> r[i];

  rep(i, n) {
    ll a1 = euclid(sx, sy, x[i], y[i]);
    ll a2 = euclid(tx, ty, x[i], y[i]);
    ll b = r[i] * r[i];
    if (a1 == b) s = i;
    if (a2 == b) t = i;
  }

  rep(i, n) {
    loop(j, i + 1, n - 1) {
      ll a = euclid(x[i], y[i], x[j], y[j]);
      ll b = (r[i] - r[j]) * (r[i] - r[j]);
      ll c = abs(r[i] + r[j]) * abs(r[i] + r[j]);
      if (b <= a && a <= c) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  dfs(s, t);

  if (!f) cout << "No" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
