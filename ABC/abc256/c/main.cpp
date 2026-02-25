// abc256 C - Filling 3x3 array
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

// 端を固定する
// a b ?
// c d ?
// ? ? 

void solve () {
  vl h(3), w(3);
  rep(i, 3) cin >> h[i];
  rep(i, 3) cin >> w[i];

  ll ans = 0;

  loop(a, 1, 30) {
    loop(b, 1, 30) {
      loop(c, 1, 30) {
        loop(d, 1, 30) {
          vl t;
          t.push_back(h[0] - a - b);
          t.push_back(h[1] - c - d);
          t.push_back(w[0] - a - c);
          t.push_back(w[1] - b - d);

          bool f = 1;
          rep(i, 4) {
            if (t[i] < 1) f = 0;
          }

          if (!f) break;

          if (w[2] - t[0] - t[1] == h[2] - t[2] - t[3]
              && h[2] - t[2] - t[3] >= 1) {
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
