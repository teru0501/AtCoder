// joi2023yo2 A - 年齢の差 (Age Difference)
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
// 最大の年齢上位２と最小の年齢上位２をもつ
// ============================================ //

void solve () {
  int n;
  cin >> n;
  vll mx(2, -1);
  vll mn(2, -1);
  vll a(n);
  rep0 (i, n) {
    cin >> a[i];
    // 最大
    if (mx[0] == -1 || mx[0] < a[i]) {
      mx[1] = mx[0];
      mx[0] = a[i];
    }
    else if (mx[1] == -1 || mx[1] < a[i]) mx[1] = a[i];
    // 最小
    if (mn[0] == -1 || mn[0] > a[i]) {
      mn[1] = mn[0];
      mn[0] = a[i];
    }
    else if (mn[1] == -1 || mn[1] < a[i]) mn[1] = a[i];
  }

  rep0 (i, n) {
    ll tmp1;
    if (a[i] == mx[0]) tmp1 = abs(a[i] - mx[1]);
    else tmp1 = abs(a[i] - mx[0]);
    ll tmp2;
    if (a[i] == mn[0]) tmp2 = abs(a[i] - mn[1]);
    else tmp2 = abs(a[i] - mn[0]);
    OUT(max(tmp1, tmp2));
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
