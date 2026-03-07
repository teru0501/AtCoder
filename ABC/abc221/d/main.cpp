// abc221 D - Online games
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
  
  vector<pair<ll, char>> v;
  rep(i, n) {
    ll a, b; cin >> a >> b;
    v.push_back({a, 'a'});
    v.push_back({a + b - 1, 'b'});
  }
  sort(all(v));

  // 入るときに入る中で一番遠いものとの距離を＋＋
  // 出るときには出た中で一番近いものとの距離を＋＋

  deque<ll> dq1, dq2;
  vl ans(n + 1, 0);
  ll cnt = 0;

  rep(i, n * 2) {
    auto [x, y] = v[i];
    if (y == 'a') {
      if (!dq1.empty()) {
        ll t = dq1.front(); dq1.pop_front();
        ans[cnt] += x - t;
      }
      dq1.push_back(x);
      cnt++;
    }
    else {
      if (!dq2.empty()) {
        ll t = dq2.back(); dq2.front();
        ans[cnt] += x - t + 1;
      }
      dq2.push_back(x);
      cnt--;
    }
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
