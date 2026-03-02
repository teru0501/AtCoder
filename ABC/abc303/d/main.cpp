// abc303 D - Shift vs. CapsLock
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
using pll = pair<ll, ll>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lower(v, x) lower_bound(all(v), x)
#define upper(v, x) upper_bound(all(v), x)
#define rep(i,n) for (ll i=0;i<(ll)n;i++)
#define rrep(i,n) for (ll i=(n)-1;i>=(ll)0;i--)
#define loop(i,m,n) for(ll i=m;i<=(ll)n;i++)
#define rloop(i,m,n) for(ll i=m;i>=(ll)n;i--)

// ================= CONST ================= //
const vl dx = {-1,0,1,0};
const vl dy = {0,1,0,-1};
const vl dx8 = {-1,-1,-1,0,1,1,1,0};
const vl dy8 = {-1,0,1,1,1,0,-1,-1};
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

// dp

void solve () {
  ll x, y, z;
  string s;
  cin >> x >> y >> z >> s;

  ll n = s.size();

  ll dp[n + 1][2];
  dp[0][0] = 0;
  dp[0][1] = INF;

  loop(i, 1, n) {
    if (s[i - 1] == 'A') {
      // 普通に押す
      dp[i][1] = dp[i - 1][1] + x;  
      dp[i][0] = dp[i - 1][0] + y;
      // capsOnにしてからする場合
      chmin(dp[i][1], dp[i - 1][0] + x + z);
      chmin(dp[i][0], dp[i - 1][1] + y + z);
    }
    else {
      // 普通に押す
      dp[i][1] = dp[i - 1][1] + y;  
      dp[i][0] = dp[i - 1][0] + x;
      // capsOffにしてからする場合
      chmin(dp[i][0], dp[i - 1][1] + x + z);
      chmin(dp[i][1], dp[i - 1][0] + y + z);
    }
  }

  cout << min(dp[n][0], dp[n][1]) << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
