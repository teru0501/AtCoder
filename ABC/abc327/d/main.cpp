// abc327 D - Good Tuple Problem
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

void solve () {
  ll n, m;
  cin >> n >> m;

  vvl g(n + 1);
  vl a(m), b(m);
  rep(i, m) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, m) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
    if (a[i] == b[i]) {
      cout << "No" << "\n";
      return;
    }
  }

  vl nibu(n + 1, -1);
  loop(i, 1, n) {
    if (nibu[i] == -1) {
      nibu[i] = 0;
      queue<ll> q;
      q.push(i);
      while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for (auto to : g[v]) {
          if (nibu[to] == -1) {
            nibu[to] = !nibu[v];
            q.push(to);
          }
          else if (nibu[to] == nibu[v]) {
            cout << "No" << "\n";
            return;
          }
        }
      }
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
