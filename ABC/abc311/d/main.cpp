// abc311 D - Grid Ice Floor
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

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<vector<bool>> vis(n, vector<bool>(m, 0));

  queue<pll> q;
  q.push({1, 1});
  vis[1][1] = 1;

  while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    rep(i, 4) {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      bool f = 0;
      while(in_grid(nx, ny, n, m) && s[nx][ny] == '.') {
        if (!vis[nx][ny]) {
          vis[nx][ny] = 1;
          f = 1;
        }
        else f = 0;
        nx += dx[i];
        ny += dy[i];
      }
      nx -= dx[i];
      ny -= dy[i];
      if (f)
        q.push({nx, ny});
    }
  }
  
  ll ans = 0;
  rep(i, n) rep(j, m) if(vis[i][j]) ans++;

  cout << ans << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
