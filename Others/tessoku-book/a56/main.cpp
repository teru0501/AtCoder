// tessoku-book A56 - String Hash
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
  ll n, q;
  string s;
  cin >> n >> q >> s;
  ll k = 100;
  
  vl h(n + 1);
  vl p(n + 1);

  p[0] = 1;
  loop(i, 1, n) {
    p[i] = (p[i - 1] * ll(100)) % MOD;
  }

  h[0] = 0;
  // ハッシュ計算
  loop(i, 1, n) {
    ll t = s[i - 1] - 'a'  + 1;
    h[i] = (h[i - 1] *  k + t) % MOD;
  }

  while(q--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll l = (h[b] - p[b - a + 1] * h[a - 1] % MOD + MOD) % MOD;
    ll r = (h[d] - p[d - c + 1] * h[c - 1] % MOD + MOD) % MOD;
    if (l == r) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
