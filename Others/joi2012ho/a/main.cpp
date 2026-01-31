// joi2012ho A - JJOOII (JJOOII)
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
// ランレングス圧縮をしてJ, O, Iと3連続並んでいたら
// その中で一番数が少ないものがその部分文字列のレベルである
// ============================================ //

vector<pair<char, int>> RLE(const string& s) {
  vector<pair<char, int>> res;
  res.reserve(s.size());
  for (auto tmp : s) {
    if (res.empty() || res.back().first != tmp) res.emplace_back(tmp, 1);
    else res.back().second++;
  }
  return res;
}

void solve () {
  string s;
  cin >> s;
  auto a = RLE(s);
  int n = a.size();
  int ans = 0;
  rep0 (i, n - 2) {
    if (a[i].first == 'J' && a[i + 1].first == 'O' && a[i + 2].first == 'I') {
      if (a[i + 1].second <= a[i].second && a[i + 1].second <= a[i + 2].second) {
        int sum = min(a[i].second, min(a[i + 1].second, a[i + 2].second));
        ans = max(sum, ans);
      }
    }
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
