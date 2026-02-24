// abc445 C - Sugoroku Destination
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

// i == xの時はその番号
// 集合で管理→その番号に落ち着く

vector<bool> vis;
vl a;
ll cnt = 0;
vl ans;
vl sum;

void dfs(ll v) {
  vis[v] = 1;
  ans[v] = cnt;
  if (a[v] == v) {
    sum.push_back(v);
    return;
  }
  dfs(a[v]);
}

void solve () {
  ll n;
  cin >> n;
  a.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  ans.assign(n + 1, -1);

  loop(i, 1, n) cin >> a[i];
  loop(i, 1, n) {
    if (!vis[i]) {
      dfs(i);
      cnt++;
    }
  }
  loop(i, 1, n) {
    if (i != 1) cout << " ";
    cout << sum[ans[i]];
  } 
  cout << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
