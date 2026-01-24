// typical90 046 - I Love 46（★3）
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
// BiとCjの総和が46以下のものをsetに
// ============================================ //

void solve () {
  int n;
  cin >> n;
  unordered_map<ll, ll> um;
  vll a(n);
  vll b(n);
  vll c(n);
  IN(a);
  IN(b);
  IN(c);
  unordered_map<ll, ll> am;
  unordered_map<ll, ll> bm;
  unordered_map<ll, ll> cm;
  rep0 (i, n) {
     a[i] %= 46;
     am[a[i]]++;
  }
  rep0 (i, n) {
     b[i] %= 46;
     bm[b[i]]++;
  }
  rep0 (i, n) {
     c[i] %= 46;
     cm[c[i]]++;
  }
  ll ans = 0;
  for (auto [x1, y1] : am) {
    for (auto [x2, y2] : bm) {
        for (auto [x3, y3] : cm) {
            if ((x1 + x2 + x3) % 46 == 0) {
                ans += y1 * y2 * y3;
            }
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
