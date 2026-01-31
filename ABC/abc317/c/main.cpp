// abc317 C - Remembering the Days
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define OUT(x) cout << (x) << endl
#define rep1(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,n) for(int i = 1; i <= (n); ++i)

const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dx = {-1,0,1,1,1,0,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

template <class T>
void VOUT(const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

template <class T>
void VVOUT(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        VOUT(v);
    }
}

vector<vector<pair<int, int>>> g;
vector<bool> vis;
ll ans  = 0;

void dfs (int v, ll cost) {
    vis[v] = 1;
    ans = max(cost, ans);
    for (auto [to1, to2] : g[v]) {
        if (!vis[to1]) {
            ll tmp = cost + to2;
            dfs(to1, tmp);
        } 
    }
    vis[v] = 0;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n, m;
  cin >> n >> m;
  g.reserve(n + 1);
  rep2 (i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  rep2 (i, n) {
    vis.assign(n + 1, 0);
    ll cost = 0;
    dfs(i, 0);
  }
  OUT(ans);
  return 0;
}
