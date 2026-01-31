// arc005 C - 器物損壊！高橋君
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

  deque<pair<ll, ll>> q;
  vvl dist(h, vl(w, INF)); // 塀を通った最小回数
  ll gx, gy;

  rep(i, h) rep(j, w) {
    if (g[i][j] == 's') {
      q.push_back({i, j});
      dist[i][j] = 0;
    }
    else if (g[i][j] == 'g') {
      gx = i;
      gy = j;
    }
  }

  while (!q.empty()) {
    ll nx = q.front().first;
    ll ny = q.front().second;
    q.pop_front();
    rep(i, 4) {
      ll tox = nx + dx[i];
      ll toy = ny + dy[i];
      ll cost = 0;
      if (in_grid(tox, toy, h, w)) {
        if (g[tox][toy] == '#') cost++;
        if (dist[nx][ny] + cost < dist[tox][toy]) {
          dist[tox][toy] = dist[nx][ny] + cost;
          if (cost == 0) q.push_front({tox, toy});
          else if (cost == 1) q.push_back({tox, toy}); 
        }
      }
    }
  }
  if (dist[gx][gy] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
