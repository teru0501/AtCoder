// abc054 C - One-stroke Path
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

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for (ll i=0;i<(ll)n;i++)
#define rrep(i,n) for (ll i=(n)-1;i>=(ll)0;i--)
#define loop(i,m,n) for(ll i=m;i<=(ll)n;i++)
#define rloop(i,m,n) for(ll i=m;i>=(ll)n;i--)

// ================= CONST ================= //
const vl dx = {-1,0,1,0};
const vl dy = {0,1,0,-1};
//const vl dx = {-1,-1,-1,0,1,1,1,0};
//const vl dy = {-1,0,1,1,1,0,-1,-1};
const ll INF = 4e18;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

// 順列全探索
// 0-indexed

void solve () {
  ll n, m;
  cin >> n >> m;
  vvl g(n);
  vl tmp(n);
  ll ans = 0;
  rep(i, n) tmp[i] = i;
  while (m--) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  do {
    bool ok1 = 1; // この順列のパスは存在するか？
    rep(i, n - 1) {
      if (!ok1) break;
      bool ok2 = 0; // vからv + 1へ行けるか？
      ll v = tmp[i];
      ll nv = tmp[i + 1];
      for (auto to : g[v]) {
        if (to == nv) {
          ok2 = 1;
          break;
        }
      }
      if (!ok2) ok1 = 0;
    }
    if (ok1) ans++;
  } while(next_permutation(tmp.begin() + 1, tmp.end()));

  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
