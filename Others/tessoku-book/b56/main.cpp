// tessoku-book B56 - Palindrome Queries
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

// 左右からハッシュをとる

void solve () {
  ll n, q;
  string s;
  cin >> n >> q >> s;
  ll k = 100;
  vl hf(n + 2);
  vl hb(n + 2);
  
  hf[0] = 0;
  loop(i, 1, n) {
    ll t = s[i - 1] - 'a'  + 1;
    hf[i] = (hf[i - 1] *  k + t) % MOD;
  }

  hb[n + 1] = 0;  
  rloop(i, n, 1) {
    ll t = s[i - 1] - 'a'  + 1;
    hb[i] = (hb[i + 1] *  k + t) % MOD;
  }

  vl p(n + 1);
  p[0] = 1;
  loop(i, 1, n) {
    p[i] = (p[i - 1] * ll(100)) % MOD;
  }

  while(q--) {
    ll l, r;
    cin >> l >> r;
    ll mae = (hf[r] - hf[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
    ll ushi = (hb[l] - hb[r + 1] * p[r - l + 1] % MOD + MOD) % MOD;

    if (mae == ushi) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
