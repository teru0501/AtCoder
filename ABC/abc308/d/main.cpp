// abc308 D - Snuke Maze
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

ll h, w;
vector<string> s;
vector<vector<bool>> vis;
bool fin = 0;

vector<char> snuke = {'s', 'n', 'u', 'k', 'e'};
unordered_map<char, ll> mp = {{'s', 0}, {'n', 1}, {'u', 2}, {'k', 3}, {'e', 4}};

void dfs(ll x, ll y, ll prv) {
  // check
  if (fin) return;
  if (s[x][y] != snuke[(prv + 1) % 5]) return;

  // ans
  if (x == h - 1 && y == w - 1) {
    cout << "Yes" << "\n";
    fin = 1;
    return;
  }

  vis[x][y] = 1;

  rep(i, 4) {
    ll tx = x + dx[i];
    ll ty = y + dy[i];
    if (in_grid(tx, ty, h, w)) {
      ll cost = 0;
      if (!vis[tx][ty]) dfs(tx, ty, mp[s[x][y]]);
      if (fin) return;
    }
  }

}

void solve () {
  cin >> h >> w;

  s.assign(h, "");
  vis.assign(h, vector<bool>(w, 0));


  rep(i, h) {
    cin >> s[i];
  }

  dfs(0, 0, 4);

  if (!fin) cout << "No" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
