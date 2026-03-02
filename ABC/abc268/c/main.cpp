// abc268 C - Chinese Restaurant
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
  
  // 0-indexed
  vl p(n);
  vl mp(n, -1);

  rep(i, n) {
    cin >> p[i];
    mp[p[i]] = i;
  }

  vl sum(n + 1, 0);
  // i回回した時の喜ぶ人の人数

  rep(i, n) {
    ll x = (p[i] + 1 + n) % n;
    ll y = (p[i] - 1 + n) % n;
    ll z = p[i];
    // --1
    if (x < i) x += n;
    x -= i;
    sum[x]++;
    if (y < i) y += n;
    y -= i;
    sum[y]++;
    if (z < i) z += n;
    z -= i;
    sum[z]++;
  }

  ll ans = *max_element(all(sum));
  cout << ans << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
