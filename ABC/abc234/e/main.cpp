// abc234 E - Arithmetic Number
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
const ll INF = 9223372036854775807LL;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion


ll fnc (ll x, ll cnt, ll k, ll d) {
  if (k == cnt) return x;
  cnt++;
  ll it = x % 10;
  if (it + d >= 0 && it + d <= 9) {
    x *= 10;
    x += it + d;

    x = fnc(x, cnt, k, d);
    if (x == -1) return -1;
    else return x;
  }
  else return -1;
}

void solve () {
  ll n;
  cin >> n;
  
  string s = to_string(n);
  ll k = s.size();
  ll x = s[0] - '0';

  vl sum;

  loop(i, -10, 10) {
    sum.push_back(fnc(x, 1, k, i));
  }

  ll nxt = x + 1;
  if (to_string(nxt).length() == 2) {
    k++;
    nxt = 1;
  }

  loop(i, -10, 10) {
    sum.push_back(fnc(nxt, 1, k, i));
  }
  
  sort(all(sum));
  ll m = sum.size();
  rep(i, m) {
    if (sum[i] >= n && sum[i] != -1) {
      cout << sum[i] << "\n";
      return;
    } 
  }
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
