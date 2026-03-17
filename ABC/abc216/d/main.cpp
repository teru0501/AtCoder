// abc216 D - Pair of Balls
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
  ll n, m;
  cin >> n >> m;

  vector<queue<ll>> q(m);
  rep(i, m) {
    ll k; cin >> k;
    rep(j, k) {
      ll a; cin >> a;
      q[i].push(a);
    }
  }
  
  queue<pll> p;
  map<ll, ll> mp;
  map<ll, ll> idx;

  rep(i, m) {
    ll x = q[i].front();
    q[i].pop();
    mp[x]++;
    if (mp[x] == 2) p.push({idx[x], i});
    else idx[x] = i;
  }

  while(!p.empty()){
    auto [a, b] = p.front();
    p.pop();
    // x
    if (!q[a].empty()) {
      ll x = q[a].front();
      q[a].pop();
      mp[x]++;
      if (mp[x] == 2) p.push({idx[x], a});
      else idx[x] = a;
    }
    // y
    if (!q[b].empty()) {
      ll x = q[b].front();
      q[b].pop();
      mp[x]++;
      if (mp[x] == 2) p.push({idx[x], b});
      else idx[x] = b;
    }
  }

  rep(i, m) {
    if (!q[i].empty()) {
      cout << "No" << "\n";
      return;
    }
  }

  cout << "Yes" << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
