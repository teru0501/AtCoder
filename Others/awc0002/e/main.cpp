// awc0002 E - Assortment of Sweets
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

// 半分列挙

void solve () {
  ll n, s;
  cin >> n >> s;
  ll x = n / 2;
  ll y = n - (n / 2);
  vl a(x);
  vl b(y);

  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];

  unordered_map<ll, ll> asum;
  unordered_map<ll, ll> bsum;
  
  loop(bit, 0, (1 << x) - 1) {
    ll tmp = 0;
    rep(i, x) {
      if (bit & (1 << i)) tmp += a[i];
    }
    asum[tmp]++;
  }

  loop(bit, 0, (1 << y) - 1) {
    ll tmp = 0;
    rep(i, y) {
      if (bit & (1 << i)) tmp += b[i];
    }
    bsum[tmp]++;
  }

  ll ans = 0;

  for (auto [tmp1, tmp2] : asum) {
    ans += tmp2 * bsum[s - tmp1];
  }

  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
