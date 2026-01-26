// arc061 C - Many Formulas
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for (ll i=0;i<(ll)n;i++)
#define rrep(i,n) for (ll i=(n)-1;i>=(ll)0;i--)
#define loop(i,m,n) for(ll i=m;i<=(ll)n;i++)
#define rloop(i,m,n) for(ll i=m;i>=(ll)n;i--)

// ================= CONST ================= //
const vl dx = {-1,0,1,0};
const vl dy = {0,1,0,-1};
//const vl dx = {-1,-1,-1,0,1,1,1,0};
//const vl dy = {-1,0,1,1,1,0,-1,-1};
const ll INF = 4e18;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

void solve () {
  string s;
  cin >> s;
  int n = s.length();
  vl a(n);
  rep(i, n) a[i] = s[i] - '0';

  ll ans = 0;
  // 0から2^(n-1)までbit全探索
 loop(bit, 0, (1 << n - 1) - 1) {
    ll tmp = 1;
    ll sum = 0;
    rrep(i, n) {
      sum += a[i] * tmp;
      tmp *= 10;
      if (bit & (1 << i - 1)) {
        tmp = 1;
      }
    }
    ans += sum;
  }
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
