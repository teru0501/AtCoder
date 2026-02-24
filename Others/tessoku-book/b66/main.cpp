// tessoku-book B66 - Typhoon
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
};

void solve () {
  ll n, m;
  cin >> n >> m;

  UnionFind uf(n);

  unordered_set<ll> st;

  vl a(m + 1), b(m + 1);
  loop(i, 1, m) cin >> a[i] >> b[i];

  ll q;
  cin >> q;
  vvl rq(q);

  rep(i, q) {
    ll t;
    cin >> t;
    rq[i].push_back(t);
    if (t == 1) {
      ll x;
      cin >> x;
      st.insert(x);
      rq[i].push_back(x);
    }
    else {
      ll u, v;
      cin >> u >> v;
      rq[i].push_back(u);
      rq[i].push_back(v);
    }
  }

  loop(i, 1, m) {
    if (!st.count(i)) {
      uf.unite(a[i], b[i]);
    }
  }
  
  reverse(all(rq));

  vector<string> ans;

  rep(i, q) {
    ll t = rq[i][0];

    if (t == 1) {
      ll x = rq[i][1];
      uf.unite(a[x], b[x]);
    }
    else {
      ll u = rq[i][1];
      ll v = rq[i][2];
      if (uf.same(u, v)) ans.push_back("Yes");
      else ans.push_back("No");
    }
  }

  reverse(all(ans));
  ll sz = ans.size();
  rep(i, sz) {
    cout << ans[i] << endl;
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
