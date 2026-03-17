// abc216 E - Amusement Park
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

// 二分探索

bool fnc(ll x, ll n, ll k, vl& a) {
  ll sum = 0;
  rep(i, n) {
    sum += max(0LL, a[i] - x + 1);
  }
  if (sum <= k) return 1;
  else return 0;
}

void solve () {
  ll n, k;
  cin >> n >> k;

  vl a(n);
  rep(i, n) cin >> a[i];


  sort(rall(a));

  ll left = 0, right = 2 * 1e9 + 1;

  
  while(right - left > 1) {
    ll mid = (right + left) / 2;
    if (fnc(mid, n, k, a)) right = mid;
    else left = mid;
  }
  
  ll h = right;
  ll cnt = 0;
  ll ans = 0;

  rep(i, n) {
    ans += max(0LL, (h + a[i]) * (a[i] - h + 1) / 2);
    cnt += max(0LL, (a[i] - h + 1));
  }

  ans += (k - cnt) * (h - 1);

  cout << ans << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
