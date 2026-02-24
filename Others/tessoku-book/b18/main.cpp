// tessoku-book B18 - Subset Sum with Restoration
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

void solve () {
  ll n, s;
  cin >> n >> s;
  
  vl a(n + 1, 0);
  loop(i, 1, n) cin >> a[i];

  bool dp[n + 1][s + 1];

  loop(i, 0, s) dp[0][i] = 0;

  dp[0][0] = 1;

  loop(i, 1, n) {
    loop(j, 0, s) {
      if (dp[i - 1][j]) dp[i][j] = 1;
      else dp[i][j] = 0;
      if (j >= a[i]) {
        if (dp[i - 1][j - a[i]]) dp[i][j] = 1;
      }
    }
  }

  if (!dp[n][s]) {
    cout << -1 << endl;
    return;
  }

  vl prv;
  ll now = n;
  ll sum = s;

  while(now > 0) {
    if (dp[now - 1][sum]) {
      now = now - 1;
    }
    else if (sum >= a[now] && dp[now - 1][sum - a[now]]) {
      sum -= a[now];
      prv.push_back(now);
      now = now - 1;
    }
  }

  reverse(all(prv));
  ll sz = prv.size();
  cout << sz << endl;

  rep(i, sz) {
    if (i) cout << " ";
    cout << prv[i];
  }
  cout << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
