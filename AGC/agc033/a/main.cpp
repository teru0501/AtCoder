// agc033 A - Darker and Darker
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

// BFS

void solve () {
  ll h, w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i, h) cin >> g[i];

  ll ans = 0; // 最大操作回数
  queue<ll> qx;
  queue<ll> qy;
  vvl dist(h, vl(w, -1));

  rep(i, h) rep(j, w) if (g[i][j] == '#') {
    qx.push(i);
    qy.push(j);
    dist[i][j] = 0;
  }

  while (!qx.empty()) {
    ll x = qx.front();
    ll y = qy.front();
    qx.pop(), qy.pop();

    rep(i, 4) {
      ll tox = x + dx[i];
      ll toy = y + dy[i];
      if (in_grid(tox, toy, h, w)) {
        if (dist[tox][toy] == -1) {
          qx.push(tox);
          qy.push(toy);
          dist[tox][toy] = dist[x][y] + 1;
        }
      }
    }
    chmax(ans, dist[x][y]);
  }
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
