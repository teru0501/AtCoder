// abc292 D - Unicyclic Components
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

// DFS 自己ループや重なり辺は無視
// vに連結成分を保存
// cntで順番を管理

vvl g;
ll cnt = 0;
vector<ll> comp;

void dfs(ll v) {
  comp[v] = cnt;
  for (auto to : g[v]) {
  if (comp[to] == -1) dfs(to);
  }
}

void solve () {
  ll n, m;
  cin >> n >> m;

  g.resize(n + 1);
  comp.assign(n + 1, -1);

  vl u(m), v(m);

  rep(i, m) {
    cin >> u[i] >> v[i];
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }

  loop(i, 1, n) {
    if (comp[i] == -1) {
      dfs(i);
      cnt++;
    }
  }


  vl a(cnt, 0);
  vl b(cnt, 0);

  loop(i, 1, n) a[comp[i]]++;

  rep(i, m) b[comp[u[i]]]++;
  
  rep(i, cnt) {
    if (a[i] != b[i]) {
      cout << "No" << "\n";
      return;
    }
  }

  cout << "Yes" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
