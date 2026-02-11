// abc276 E - Round Trip
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

// BFS

void solve () {
  ll h, w;
  cin >> h >> w;
  vector<string> g(h);

  rep(i, h) cin >> g[i];

  vvl dist(h, vl(w, -1));
  queue<pll> q;
  
  rep(i, h) rep(j, w) {
    if (g[i][j] == 'S') {
      g[i][j] = '#';
      ll cnt = 1;
      rep(k, 4) {
        ll to1 = i + dx[k];
        ll to2 = j + dy[k];
        if (in_grid(to1, to2, h, w)) {
          if (g[to1][to2] == '.') {
            q.push({to1, to2});
            dist[to1][to2] = cnt;
            cnt++;
          }
        }
      }
    }
  }

  while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    rep(i, 4) {
      ll tox = x + dx[i];
      ll toy = y + dy[i];
      if (in_grid(tox, toy, h, w)) {
        if (g[tox][toy] == '.') {
          if (dist[tox][toy] == -1) {
            q.push({tox, toy});
            dist[tox][toy] = dist[x][y];
          }
          else if (dist[tox][toy] != dist[x][y]) {
            cout << "Yes" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
