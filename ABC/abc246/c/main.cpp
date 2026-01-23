// abc246 C - Coupon
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
// 余りが0の商品をまずクーポン適用する
// xで割ったときの余りが大さいものからクーポンを使っていく
// ============================================ //

void solve () {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<pll> a(n);
  rep0 (i, n) {
    ll tmp;
    cin >> tmp;
    a[i] = {tmp % x, tmp};
  }
  ll ans = 0;
  sort(all(a));
  for (auto& [fst, scd] : a) {
    if (fst == 0 && k > 0) {
      ll use = (scd / x);;
      use = min(use, k);
      scd = max(ll(0), scd - x * use);
      ans += scd;
      k -= use;
    }
    else break;
  }

  sort(rall(a));
  for (auto& [fst, scd] : a) {
    // 使う数
    ll use;
    if (fst != 0) use = (scd / x) + 1;
    else use = (scd / x);
    use = min(use, k);
    // 適用
    scd = max(ll(0), scd - x * use);
    ans += scd;
    // 減らす
    k -= use;
  }
  OUT(ans);
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
