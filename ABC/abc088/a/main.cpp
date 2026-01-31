// abc088 A - Infinite Coins
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
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
const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
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
// ============================================ //

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  ll h, w;
  cin >> h >> w;
  vector<string> g(h);
  IN(g);
  ll cnt = 0;
  rep0 (i, h) {
    rep0 (j, w) {
      if (g[i][j] == '#') cnt++;
    }
  }
  queue<ll> qx;
  queue<ll> qy;
  qx.push(0);
  qy.push(0);
  vvi dist(h, vi(w, -1));
  dist[0][0] = 0;
  while(!qx.empty()) {
    ll vx = qx.front();
    ll vy = qy.front();
    qx.pop(), qy.pop();
    rep0 (i, 4) {
      ll nx = vx + dx[i];
      ll ny = vy + dy[i];
      if (in_grid(nx, ny, h, w)) {
        if (g[nx][ny] == '.' && dist[nx][ny] == -1) {
          dist[nx][ny] = dist[vx][vy] + 1;
          qx.push(nx), qy.push(ny);
        }
      }
    }
  }
  if (dist[h - 1][w - 1] == -1) {
    OUT(-1);
    return 0;
  }
  ll ans = (h * w) -(dist[h - 1][w - 1] + 1 + cnt);
  OUT(ans);
  return 0;
}
