// past202012-open H - Conveyor
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

ll h, w, r, c;  
vector<string> s;
vector<vector<bool>> vis;
map<char, pll> mp;
map<char, pll> mp1;

void dfs(ll x, ll y) {
  vis[x][y] = 1;

  rep(i, 4) {
    ll nx = x + dx[i];
    ll ny = y + dy[i];
    if (in_grid(nx, ny, h, w)) {
      if (s[nx][ny] == '#' || vis[nx][ny]) continue;
      if (s[nx][ny] == '.') {
        dfs(nx, ny);
      }
      else {
        ll tx = nx + mp1[s[nx][ny]].first;
        ll ty = ny + mp1[s[nx][ny]].second;
        if (tx == x && ty == y) {
          dfs(nx, ny);
        } 
      }
    } 
  }
}
void solve () {
  cin >> h >> w >> r >> c;
  r--, c--;
  s.resize(h);
  vis.assign(h, vector<bool>(w, 0));

  rep(i, h) cin >> s[i];
  
  mp1['<'] = {0, -1};
  mp1['^'] = {-1, 0};
  mp1['>'] = {0, 1};
  mp1['v'] = {1, 0};

  dfs(r, c);

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') cout << "#";
      else if (vis[i][j]) cout << "o";
      else cout << "x";
    }
    cout << "\n";
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
