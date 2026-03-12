// abc304 E - Good Graph
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

struct UnionFind
{
  vl p, sz;

  UnionFind(ll n) {
    p.assign(n + 1, -1);
    sz.assign(n + 1, 1);
  }

  ll root(ll x) {
    if (p[x] == -1) return x;
    return p[x] = root(p[x]);
  }

  void unite(ll _a, ll _b) {
    ll a = root(_a);
    ll b = root(_b);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
  }

  bool same(ll u, ll v) {
    return root(u) == root(v);
  }

  ll ans (ll v) {
    return root(v);
  }
};

void solve () {
  ll n, m;
  cin >> n >> m;

  UnionFind uf(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    uf.unite(u, v);
  }

  map<ll, set<ll>> mp;

  ll k;
  cin >> k;
  rep(i, k) {
    ll x, y;
    cin >> x >> y;
    mp[uf.ans(x)].insert(uf.ans(y));
    mp[uf.ans(y)].insert(uf.ans(x));
  }

  ll q;
  cin >> q;
  while(q--) {
    ll p, q;
    cin >> p >> q;
    if (mp[uf.ans(p)].count(uf.ans(q))) {
      cout << "No" << "\n";
    }
    else cout << "Yes" << "\n";
  }
  
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
