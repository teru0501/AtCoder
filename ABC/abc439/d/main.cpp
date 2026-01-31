// abc439 D - Kadomatsu Subsequence
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

// 数字が出る頻度をまとめる
//左からする場合と右からする場合での計算をする

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vi a(n);
  IN(a);
  ll ans = 0;
  unordered_map<ll, ll> um1;
  unordered_map<ll, ll> um2;
  for (auto tmp : a) {
    um1[tmp]++;
    um2[tmp]++;
  }
  // 左
  for (int j = 0; j < n; j++) {
    um1[a[j]]--;
    if (a[j] % 5 == 0) {
      int i = 7 * (a[j] / 5);
      int k = 3 * (a[j] / 5);
      ans += um1[i] * um1[k];
    }
  }
  // 右
  for (int j = n - 1; j >= 0; j--) {
    um2[a[j]]--;
    if (a[j] % 5 == 0) {
      int i = 7 * (a[j] / 5);
      int k = 3 * (a[j] / 5);
      ans += um2[i] * um2[k];
    }
  }
  OUT(ans);
  return 0;
}
