// abc275 A - Find Takahashi
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
  vector<string> g(9);
  vector<pll> v;
  rep(i, 9) {
    cin >> g[i];
    rep(j, 9) {
      if (g[i][j] == '#') v.push_back({i, j});
    }
  }

  ll ans = 0;

  ll n = v.size();

  loop(a, 0, n - 1) {
    loop(b, a + 1, n - 1) {
      loop(c, b + 1, n - 1) {
        loop(d, c + 1, n - 1) {
          vl tmp = {a, b, c, d};
          vl dist;
          loop(x, 0, 3) {
            loop(y, x + 1, 3) {
              ll t1 = abs(v[tmp[x]].first - v[tmp[y]].first);
              ll t2 = abs(v[tmp[x]].second - v[tmp[y]].second);
              dist.push_back(t1 * t1 + t2 * t2);
            }
          }

          sort(all(dist));
          if (dist[0] > 0 && dist[0] == dist[1] && dist[1] == dist[2] 
            && dist[2] == dist[3] && dist[4] == dist[5]
          ) ans++;
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
