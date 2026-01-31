// joi2011yo E - チーズ (Cheese)
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

vector<string> g;

// BFS
// チーズを食べるごとにBFSをしていく

void solve () {
  ll h, w, n;
  cin >> h >> w >> n;
  g.resize(h);
  ll ans = 0;
  ll nx, ny;
  rep(i, h) cin >> g[i];
  rep(i, h) rep(j, w) if (g[i][j] == 'S') nx = i, ny = j;
  loop(cheese, 1, n) {
    queue<ll> qx;
    queue<ll> qy;
    qx.push(nx), qy.push(ny);
    vvl dist(h, vl(w, -1));
    dist[nx][ny] = 0;
    while (!qx.empty()) {
      ll x = qx.front();
      ll y = qy.front();
      qx.pop(), qy.pop();
      // チーズ確認
      if (g[x][y] - '0' == cheese) {
        ans += dist[x][y];
        nx = x, ny = y;
        break;
      }
      // BFS
      rep(i, 4) {
        ll tox = x + dx[i];
        ll toy = y + dy[i];
        if (in_grid(tox, toy, h, w)) {
          if (dist[tox][toy] == -1 && g[tox][toy] != 'X') {
            qx.push(tox);
            qy.push(toy);
            dist[tox][toy] = dist[x][y] + 1;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
