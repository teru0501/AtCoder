// abc309 D - Add One Edge
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

void solve () {
  ll n1, n2, m;
  cin >> n1 >> n2 >> m;
  
  vvl g(n1 + n2 + 1);

  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll sum1 = 0, sum2 = 0;
  queue<ll> q;
  vl dist(n1 + n2 + 1, -1);
  q.push(1);
  dist[1] = 1;

  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    chmax(sum1, dist[v]);
    for (auto to : g[v]) {
      if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }

  q.push(n1 + n2);
  dist[n1 + n2] = 0;

  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    chmax(sum2, dist[v]);
    for (auto to : g[v]) {
      if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
  cout << sum1 + sum2 << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
