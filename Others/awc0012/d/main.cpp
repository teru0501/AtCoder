// awc0012 D - Escape from the Maze
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


// 0-1 BFS

void solve () {
  ll n, m;
  cin >> n >> m;
  
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  deque<pll> dq;
  vvl dist(n, vl(m, -1));
  dq.push_front({0, 0});
  dist[0][0] = 0;

  while(!dq.empty()) {
    auto [x, y] = dq.front();
    dq.pop_front();

    rep(i, 4) {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if (in_grid(nx, ny, n, m)) {
        if (dist[nx][ny] == -1) {
          if (s[nx][ny] == '.') {
            dist[nx][ny] = dist[x][y];
            dq.push_front({nx, ny});
          }
          else {
            dist[nx][ny] = dist[x][y] + 1;
            dq.push_back({nx, ny});
          }
        }
      }
    }
  }


  cout << dist[n - 1][m - 1] << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
