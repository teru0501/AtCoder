// joi2012yo B - サッカー (Soccer)
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
// それぞれのチームの合計得点を求める。
// ランキングをつける。
// - 合計得点とそのチームの番号を持ちながらソート
// - 
// ============================================ //

void solve () {
  int n;
  cin >> n;
  vi ans(n + 1);
  vector<pii> p(n + 1);
  rep0 (i, n + 1) {
    p[i] = {0, i};
  }

  rep0 (i, (n * (n - 1)) / 2) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > d) p[a].first += 3;
    else if (c < d) p[b].first+= 3;
    else {
      p[a].first++;
      p[b].first++;
    }
  }
  
  sort(rall(p));
  int cnt = 1;
  int d = 0;
  rep0 (i, n) {
    ans[p[i].second] = cnt;
    if (p[i].first != p[i + 1].first) {
        cnt += 1 + d;
        d = 0;
    } 
    else d++;
  }
  rep1 (i, n) OUT(ans[i]);
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
