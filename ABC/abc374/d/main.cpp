// abc374 D - Laser Marking
#include <bits/stdc++.h>
#include <math.h>
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
// 順列全探索
// ============================================ //

void solve () {
  int n, s, t;
  cin >> n >> s >> t;
  vi a(n), b(n), c(n), d(n);
  rep0 (i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<ld> v(n);
  rep0 (i, n) {
    ld tmp1 = (abs(a[i] - c[i])) * (abs(a[i] - c[i]));
    ld tmp2 = (abs(b[i] - d[i])) * (abs(b[i] - d[i]));
    v[i] = sqrt(tmp1 + tmp2) * t;
  }

  ld sum1 = accumulate(all(v), 0);
  ld m = LINF;

  vi tmp(n);
  rep0 (i, n) tmp[i] = i;
  do {
    // 1 ~ n - 1までして前との距離
    ld sum2 = 0;
    rep1 (j, n - 1) {
      // A,BとA,B
      int i = tmp[j];
      ld tmp1 = abs(a[i - 1] - a[i]) * abs(a[i - 1] - a[i]);
      ld tmp2 = abs(b[i - 1] - b[i]) * abs(b[i - 1] - b[i]);
      // A,BとC,D
      ld tmp3 = abs(a[i - 1] - c[i]) * abs(a[i - 1] - c[i]);
      ld tmp4 = abs(b[i - 1] - d[i]) * abs(b[i - 1] - d[i]);
      // C,DとA,B
      ld tmp5 = abs(c[i - 1] - a[i]) * abs(c[i - 1] - a[i]);
      ld tmp6 = abs(d[i - 1] - b[i]) * abs(d[i - 1] - b[i]);
      // C,DとC,D
      ld tmp7 = abs(c[i - 1] - c[i]) * abs(c[i - 1] - c[i]);
      ld tmp8 = abs(d[i - 1] - d[i]) * abs(d[i - 1] - d[i]);

      ld tmp9 = min(tmp1 + tmp2, tmp3 + tmp4);
      ld tmp10 = min(tmp5 + tmp6, tmp7 + tmp8);
      sum2 += sqrt(min(tmp9, tmp10)) * s;
    }
    m = min(m, sum2);
  } while(next_permutation(all(tmp)));
  OUT(ld(sum1 + m));
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
