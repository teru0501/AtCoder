// joi2011ho A - 惑星探査 (Planetary Exploration)
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

void solve () {
  int h, w, q;
  cin >> h >> w >> q;
  vector<string> g(h + 1, "?");
  rep1 (i, h) {
    string tmp;
    cin >> tmp;
    g[i] += tmp;
  }
  vvll jun(h + 1, vll(w + 1, 0));
  vvll oce(h + 1, vll(w + 1, 0));
  vvll ice(h + 1, vll(w + 1, 0));
  
  rep1 (i, h) {
    rep1 (j, w) {
      char t = g[i][j];
      if (t == 'J') jun[i][j]++;
      else if (t == 'O') oce[i][j]++;
      else if (t == 'I') ice[i][j]++;
    }
  }

  rep1 (i, h) {
    rep1 (j, w) {
      jun[i][j] += jun[i - 1][j];
      oce[i][j] += oce[i - 1][j];
      ice[i][j] += ice[i - 1][j];
    }
  }
  rep1 (i, h) {
    rep1 (j, w) {
      jun[i][j] += jun[i][j - 1];
      oce[i][j] += oce[i][j - 1];
      ice[i][j] += ice[i][j - 1];
    }
  }

  while (q--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ansj = jun[x2][y2] - jun[x1 - 1][y2] - jun[x2][y1 - 1] + jun[x1 - 1][y1 - 1];
    ll anso = oce[x2][y2] - oce[x1 - 1][y2] - oce[x2][y1 - 1] + oce[x1 - 1][y1 - 1];
    ll ansi = ice[x2][y2] - ice[x1 - 1][y2] - ice[x2][y1 - 1] + ice[x1 - 1][y1 - 1];
    cout << ansj << " " << anso << " " << ansi << endl;
  }
  
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
