// tessoku-book A09 - Winter in ALGO Kingdom
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

// 横ー縦

void solve () {
  ll h, w, n;
  cin >> h >> w >> n;
  
  vvl x(h + 2, vl(w + 2, 0));

  rep(i, n) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    x[a][b]++;
    x[a][d + 1]--;
    x[c + 1][b]--;
    x[c + 1][d + 1]++;
  }

  loop(i, 1, h) loop(j, 1, w) {
    x[i][j] += x[i][j - 1];
  }
  loop(i, 1, h) loop(j, 1, w) {
    x[i][j] += x[i - 1][j];
  }

  loop(i, 1, h) {
    loop(j, 1, w) {
      if (j != 1) cout << " ";
      cout << x[i][j];
    }
    cout << endl;
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
