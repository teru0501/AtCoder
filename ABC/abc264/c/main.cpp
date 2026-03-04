// abc264 C - Matrix Reducing
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

// bit全探索

void solve () {
  ll h1, w1;
  cin >> h1 >> w1;

  vvl a(h1, vl(w1));
  rep(i, h1) rep(j, w1) cin >> a[i][j];

  ll h2, w2;
  cin >> h2 >> w2;

  vvl b(h2, vl(w2));
  rep(i, h2) rep(j, w2) cin >> b[i][j];

  loop(bit1, 0, (1 << h1) - 1) {
    loop(bit2, 0, (1 << w1) - 1) {
      bool f = 1;

      vl rows, cols;

      rep(i, h1) if (bit1 & (1 << i)) rows.push_back(i);
      rep(i, w1) if (bit2 & (1 << i)) cols.push_back(i);
      
      if (rows.size() != h2 || cols.size() != w2) continue;

      rep(i, h2) {
        rep(j, w2) {
          if (a[rows[i]][cols[j]] != b[i][j]) f = 0;
        }
      }

      if (f) {
        cout << "Yes" << "\n";
        return;
      }
    }
  }

  cout << "No" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
