// abc304 C - Virus
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

// pq?
// 感染者をpqにぶち込む

void solve () {
  ll n, d;
  cin >> n >> d;
  d *= d;
  vector<ld> x(n);
  vector<ld> y(n);
  vector<vector<ld>> virus(n, vector<ld>(n));
  rep(i, n) {
    cin >> x[i] >> y[i];
  }
  loop(i, 0, n - 1) {
    loop(j, i + 1, n - 1) {
      ll tmp1 = abs(x[i] - x[j]) * abs(x[i] - x[j]);
      ll tmp2 = abs(y[i] - y[j]) * abs(y[i] - y[j]);
      virus[i][j] = tmp1 + tmp2;
      virus[j][i] = tmp1 + tmp2;
    }
  }

  queue<ll> q;
  set<ll> st;
  st.insert(0);
  q.push(0);
  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    rep(i, n) {
      if (i == v || st.count(i)) continue;
      if (d >= virus[v][i]) {
        st.insert(i);
        q.push(i);
      }
    }
  }
  rep(i, n) {
    if (st.count(i)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
