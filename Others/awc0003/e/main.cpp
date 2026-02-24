// awc0003 E - Cargo Delivery Truck
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

ll n, m;
vl w, c;
vl sum;
ll rest = 0; // 残り重さ
ll rem = 0; // 残り容量
bool f = 0;

// DFS
void dfs(ll v) {
  if (f) return;
  if (rest > rem) return;
  if (v == n) {
    cout << "Yes" << endl;
    f = 1;
    return;
  }
  rep(i, m) {
    sum[i] += w[v];
    rest -= w[v];
    rem -= w[v];
    if (sum[i] <= c[i])
      dfs(v + 1);
    if (f) return;
    if (rest > rem) return;
    rest += w[v];
    rem += w[v];
    sum[i] -= w[v];
  }
}

void solve () {
  cin >> n >> m;
  w.resize(n);
  c.resize(m);
  sum.assign(m, 0);
  rep(i, n) {
    cin >> w[i];
    rest += w[i];
  }
  rep(i, m) {
    cin >> c[i];
    rem += c[i];
  }

  sort(rall(w));
  sort(rall(c));

  dfs(0);
  if (!f)
    cout << "No" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
