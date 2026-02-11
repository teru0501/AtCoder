// typical90 072 - Loop Railway Plan（★4）
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
vector<string> g;
vector<vector<bool>> vis;
ll gx, gy;
ll ans = 0;

// 全探索DFS

void dfs (ll x, ll y, ll d) {
    vis[x][y] = 1;
    rep(i, 4) {
        ll tox = x + dx[i];
        ll toy = y + dy[i];
        if (in_grid(tox, toy, h, w)) {
            if (tox == gx && toy == gy) {
                chmax(ans, d);
            }
            else if (!vis[tox][toy] && g[tox][toy] == '.') {
                dfs(tox, toy, d + 1);
            }
        }
    }
    vis[x][y] = 0;
}

void solve () {
    cin >> h >> w;
    g.resize(h);
    vis.assign(h, vector<bool>(w, 0));

    rep(i, h) cin >> g[i];

    rep(i, h) rep(j, w) {
        if (g[i][j] == '.') {
            gx = i;
            gy = j;
            dfs(i, j, 1);
        }
    }
    
    if (ans < 4) ans = -1;
    cout << ans << endl;
    return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
