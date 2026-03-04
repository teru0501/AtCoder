// abc265 D - Iroha and Haiku (New ABC Edition)
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

// 尺取り三連続

void solve () {
  ll n, p, q, r;
  cin >> n >> p >> q >> r;

  vl a(n);
  rep(i, n) cin >> a[i];

  vl sum(n, 0);
  rep(i, n) {
    if (i) sum[i] += sum[i - 1];
    sum[i] += a[i];
  }

  set<ll> x;
  ll right = 0;
  ll now = 0;
  rep(i, n) {
    // 超えたら中止
    while(right < n && now < p) {
      now += a[right];
      right++;
    }
    if (now == p) x.insert(right - 1);
    now -= a[i];
  }

  set<ll> y;
  right = 0;
  now = 0;
  rep(i, n) {
    // 超えたら中止
    while(right < n && now < r) {
      now += a[right];
      right++;
    }
    if (now == r) y.insert(i);
    now -= a[i];
  }

  vector<pll> z;
  right = 0;
  now = 0;
  rep(i, n) {
    // 超えたら中止
    while(right < n && now < q) {
      now += a[right];
      right++;
    }
    if (now == q) z.push_back({i, right - 1});
    now -= a[i];
  }
  
  ll m = z.size();
  rep(i, m) {
    auto [fst, scd] = z[i];
    if (x.count(fst - 1) && y.count(scd + 1)) {
      cout << "Yes" << "\n";
      return;
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
