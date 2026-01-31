// joi2007yo F - 通学経路
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define IN(v) for (auto &x : (v)) cin >> x;
#define OUT(x) cout << (x) << endl
#define VOUT(v) do { for(auto x : (v)) cout << x << " "; cout << endl; } while(0)
#define VVOUT(vv) do { for(auto &v : (vv)) VOUT(v); } while(0)
#define rep0(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

// ================= CONST ================= //
const vi dx = {1,0};
const vi dy = {0,1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dy = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0 <= i && i < h && 0 <= j && j < w);}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

// ================= STRATEGY ================= //
// 制約をみろ！！
// 愚直を考えろ！！
// オバフロ注意！！
// グリッド変換してDFS
// ============================================ //

vector<vector<char>> g;
vector<vector<bool>> vis;
int h, w;
int cnt = 0;


void dfs (int x, int y) {
  vis[x][y] = 1;
  if (x == h - 1 && y == w - 1) {
    cnt++;
    vis[x][y] = 0;
    return;
  }
  rep0 (i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (in_grid(nx, ny, h, w)) {
      if (!vis[nx][ny] && g[nx][ny] == '.') {
        dfs(nx, ny);
      }
    }
  }
  vis[x][y] = 0;
}

void solve () {
  cin >> h >> w;
  g.assign(h, vector<char>(w, '.'));
  vis.assign(h, vector<bool>(w, 0));
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = '#';
  }
  
  if (g[0][0] != '#') {
    dfs(0, 0);
    OUT(cnt);
  }
  else OUT(0);
  return;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  solve();
  return 0;
}
