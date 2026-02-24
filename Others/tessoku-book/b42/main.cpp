// tessoku-book B42 - Two Faced Cards
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
  ll n;
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<pll> v1(n);
  vector<pll> v2(n);
  rep(i, n) {
    v1[i] = {a[i], b[i]};
    v2[i] = {b[i], a[i]};
  }

  vector<pll> t;
  ll s1, s2;
  ll ans = 0;

  // 表ー
  t = v1, s1 = 0, s2 = 0;
  sort(all(t));
  rep(i, n) {
    s1 += t[i].first;
    s2 += t[i].second;
    ll sum = abs(s1) + abs(s2);
    chmax(ans, sum);
  }
  // 表＋
  t = v1, s1 = 0, s2 = 0;
  sort(rall(t));
  rep(i, n) {
    s1 += t[i].first;
    s2 += t[i].second;
    ll sum = abs(s1) + abs(s2);
    chmax(ans, sum);
  }
  // 裏ー
  t = v2, s1 = 0, s2 = 0;
  sort(all(t));
  rep(i, n) {
    s1 += t[i].first;
    s2 += t[i].second;
    ll sum = abs(s1) + abs(s2);
    chmax(ans, sum);
  }
  // 裏＋
  t = v2, s1 = 0, s2 = 0;
  sort(rall(t));
  rep(i, n) {
    s1 += t[i].first;
    s2 += t[i].second;
    ll sum = abs(s1) + abs(s2);
    chmax(ans, sum);
  }

  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
