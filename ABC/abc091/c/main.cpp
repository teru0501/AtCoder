// abc091 C - 2D Plane 2N Points
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

// ソートされた各青い点に対して、
// x, y座標も小さく、y座標が大きい赤い点をペアリングする
void solve () {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> r(n);
  vector<pair<ll, ll>> b(n);
  rep(i, n) {
    ll tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    r[i] = {tmp1, tmp2};
  }
  rep(i, n) {
    ll tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    b[i] = {tmp1, tmp2};
  }
  ll ans = 0;
  sort(all(b));
  rep(i, n) {
    ll it = -1;
    ll mxy = -1;
    rep(j, r.size()) {
      if (b[i].first > r[j].first && b[i].second > r[j].second) {
        if (r[j].second > mxy) {
          mxy = r[j].second;
          it = j;
        }
      }
    }
    if (it != -1) {
      ans++;
      r.erase(r.begin() + it);
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
