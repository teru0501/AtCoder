// joi2007ho B - 最長の階段
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
// 連続している部分を管理する
// pair<最初の数字, 連続数>
// 一個前の最後の値 + 1とitが一致したらtmp++
// ============================================ //

void solve () {
  int n, k;
  cin >> n >> k;
  vi a(k);
  IN(a);
  sort(all(a));
  vector<pll> p;
  ll ans = 0;
  int ok = 0;
  rep0 (i, k) {
    if (a[i] == 0) {
      ok = 1;
      continue;
    }
    else if (p.empty() || p.back().first + p.back().second - 1 != a[i] - 1) p.push_back({a[i], 1});
    else p.back().second++;
    ans = max(ans, p.back().second);
  }
  if (!ok) {
    OUT(ans);
    return;
  }
  rep0 (i, p.size()) {
    // 上側
    ll it1 = p[i].first - 1;
    ll tmp1 = 0;
    if (it1 >= 1) {
      tmp1 += p[i].second + 1;
      if (i != 0) {
        int pre = p[i - 1].first + p[i - 1].second - 1;
        if (it1 - 1 == pre)
          tmp1 += p[i - 1].second;
      }
    }
    // 下側
    ll it2 = p[i].first + p[i].second - 1 + 1;
    ll tmp2 = 0;
    if (it2 <= n) {
      tmp2 += p[i].second + 1;
      if (i != p.size() - 1) {
        int nxt = p[i + 1].first;
        if (it2 + 1 == nxt)
          tmp2 += p[i + 1].second;
      }
    }
    ans = max(ans, max(tmp1, tmp2));
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
