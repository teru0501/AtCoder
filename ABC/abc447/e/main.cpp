// abc447 E - Divide Graph
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
const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion


// 考えたこと
// 辺が小さいほうからけしていく
// 連結数が2になったら、逆戻りして連結数が
// 変わらない程度にどんどんくっつけていく

struct UnionFind
{
  vl p, sz;
  ll cnt = 0; // 連結成分個数

  UnionFind(ll n) {
    p.assign(n + 1, -1);
    sz.assign(n + 1, 1);
    cnt = n;
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

    cnt--;
    p[b] = a;
    sz[a] += sz[b];
  }

  bool same(ll u, ll v) {
    return root(u) == root(v);
  }

  ll ans () {
    return cnt;
  }
};

ll power(ll b, ll e, ll m) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) {
	        res *= b;
	        res = (res + m) % m;
        }
        b *= b;
        b = (b + m) % m;
        e >>= 1;
    }
    return res;
}


void solve () {
  ll n, m;
  cin >> n >> m;
  
  vl u(m), v(m);
  rep(i, m) cin >> u[i] >> v[i];

  UnionFind uf(n);

  ll mx = 0;

  rrep(i, m) {
    if (uf.ans() == 2) {
      mx = i + 1;
      break;
    }
    uf.unite(u[i], v[i]);
  }

  ll ans = 0;
  rrep(i, mx) {
    if (!uf.same(u[i], v[i])) {
      ans += power(2LL, i + 1, MOD);
      ans %= MOD;
    }
    else uf.unite(u[i], v[i]);
  }

  cout << ans << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
