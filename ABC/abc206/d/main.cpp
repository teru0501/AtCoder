// abc206 D - KAIBUNsyo
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
const ll INF = 9223372036854775807LL;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

// たぶん噓解法

 map<ll, vl> g;
 set<ll> st;
 ll cnt;

 void dfs(ll v) {
  st.insert(v);
  cnt++;
  for (auto to : g[v]) {
    if (!st.count(to)) {
      dfs(to);
    }
  }
 }

void solve () {
  ll n;
  cin >> n;
  
  vl a(n + 1);
  loop(i, 1, n) {
    cin >> a[i];
  }

  ll ans = 0;

  loop(i, 1, n / 2 + 1) {
    if (a[i] != a[n + 1 - i]) {
      g[a[i]].push_back(a[n + 1 - i]);
      g[a[n + 1 - i]].push_back(a[i]);
    }
  }

  for (auto [x, _] : g) {
    if (!st.count(x)) {
      cnt = 0;
      dfs(x);
      ans += cnt - 1;
    }
  }

  cout << ans << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
