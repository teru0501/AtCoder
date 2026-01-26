// abc079 C - Train Ticket
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
  vl a(4);
  rep(i, 4) a[i] = s[i] - '0';
  loop(bit, 0, (1 << 3)) {
    ll sum = 0;
    rep(i, 4) {
      if (i == 0) sum += a[i];
      else if (bit & (1 << (i - 1))) sum += a[i];
      else sum -= a[i];
    } 
    if (sum == 7) {
      string ans;
      rep(i, 4) {
        if (i == 0) {}
        else if (bit & (1 << (i - 1))) ans += '+';
        else if (i != 0) ans += '-';
        ans += a[i] + '0';
      }
      ans += "=7";
      cout << ans << endl;
      return;
    }
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
