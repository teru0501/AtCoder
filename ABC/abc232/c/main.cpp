// abc232 C - Graph Isomorphism
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

// N = 8なので順列全探索

void solve () {
  ll n, m;
  cin >> n >> m;
  vector<set<ll>> taka(n);
  vector<set<ll>> aoki(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    taka[a].insert(b);
    taka[b].insert(a);
  }
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    aoki[a].insert(b);
    aoki[b].insert(a);
  }
  vl pem(n);
  rep(i, n) pem[i] = i;

  do {
    bool f = 1;
    rep(i, n) {
      for (auto v : taka[i]) {
        if (!aoki[pem[i]].count(pem[v])) {
          f = 0;
          break;
        }
      }
      if (!f) break;
    }
    if (f) {
      cout << "Yes" << endl;
      return;
    }
  } while(next_permutation(all(pem)));

  cout << "No" << endl;
  return; 
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
