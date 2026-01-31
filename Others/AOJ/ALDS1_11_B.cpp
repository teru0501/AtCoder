#include <bits/stdc++.h>
using namespace std;

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
//const vi dx = {-1,0,1,1,1,0,-1,-1};
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

vvi g;
vector<bool> vis;
vvi ans;
ll t = 0;

void dfs (int v) {
  if (vis[v]) return;
  t++;
  ans[v][0] = t;
  vis[v] = 1;
  for (int to : g[v]) {
    if (!vis[to])
      dfs(to);
  }
  t++;
  ans[v][1] = t;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  g.resize(n + 1);
  vis.assign(n + 1, 0);
  ans.resize(n + 1, vi(2, -1));
  rep1 (i, n) {
    int dummy;
    int k;
    cin >> dummy >> k;
    rep1 (j, k) {
      int tmp;
      cin >> tmp;
      g[i].push_back(tmp);
    }
  }
  rep1 (i, n) {
    dfs(i);
  }
  rep1 (i, n) {
    cout << i << " " << ans[i][0] << " " << ans[i][1] << endl;
  }
  return 0;
}
