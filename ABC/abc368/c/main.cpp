// abc368 C - Triple Attack
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
// 行動をO(1)で
// 場合分け
// t % 3 == 0  1, 1, 3, 1
// t % 3 == 1  1, 3, 1, 1
// t % 3 == 2  3, 1, 1, 3
// ============================================ //

void solve () {
  int n;
  cin >> n;
  vll a(n);
  vll tmp0 = {0, 1, 2, 5, 6};
  vll tmp1 = {0, 1, 4, 5, 6};
  vll tmp2 = {0, 3, 4, 5, 8};
  IN(a);
  ll t = 0;
  rep0 (i, n) {
    ll add = (a[i] / 5) * 3;
    a[i] %= 5;
    if (t % 3 == 0) add += lower_bound(all(tmp0), a[i]) - tmp0.begin();
    else if (t % 3 == 1) add += lower_bound(all(tmp1), a[i]) - tmp1.begin();
    else add += lower_bound(all(tmp2), a[i]) - tmp2.begin();
    t += add;
  }
  OUT(t);
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
