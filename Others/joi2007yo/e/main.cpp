// joi2007yo E - 品質検査
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
// 正常な部品を探す
// 次にもう一度ループを回して
// n * n して一意に定める
// ============================================ //

void solve () {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  vi ans(a + b + c + 1, 2);
  vi x(n), y(n), z(n), cnt(n);
  rep0 (i, n) {
    cin >> x[i] >> y[i] >> z[i] >> cnt[i];
  }
  int sum = n;
  while (sum--) {
    rep0 (i, n) {
      if (cnt[i]) {
        ans[x[i]] = 1;
        ans[y[i]] = 1;
        ans[z[i]] = 1;
      }
      else {
        // もし正常が２つだったら一つを0に
        int tmp = 0;
        int tmp1;
        if (ans[x[i]] == 1) tmp++;
        else tmp1 = x[i];
        if (ans[y[i]] == 1) tmp++;
        else tmp1 = y[i];
        if (ans[z[i]] == 1) tmp++;
        else tmp1 = z[i];
        if (tmp == 2) {
          ans[tmp1] = 0;
        }
      }
    }
  }
  rep1 (i, a + b + c) OUT(ans[i]);
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
