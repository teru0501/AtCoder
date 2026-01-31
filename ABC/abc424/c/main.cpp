// abc424 C - New Skill Acquired
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
//const vi dx = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0 <= i && i < h && 0 <= j && j < w);}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

vvi g;
vector<bool> skill;

//習得したところからDFSをする

void DFS (int v) {
    if (!skill[v]) {
        skill[v] = 1;
        for (auto to : g[v]) {
            if (!skill[to]) {
                DFS(to);
            }
        }
    }
}
// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;

  int n;
  cin >> n;
  g.reserve(n + 1);
  skill.assign(n + 1, 0);
  queue<int> q;
  rep1(i, n) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
        q.push(i);
        continue;
    }
    if (a != i)
        g[a].push_back(i);
    if (b != i)
        g[b].push_back(i);
  }
  while (!q.empty()) {
    DFS(q.front());
    q.pop();
  }
  ll ans = 0;
  rep1 (i, n) {
    if (skill[i]) ans++;
  }
  OUT(ans);
  return 0;
}
