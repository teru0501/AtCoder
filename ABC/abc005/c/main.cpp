// abc005 C - おいしいたこ焼きの売り方
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

// B - W 秒以上にできたたこやきの中で一番小さいものを選ぶ

void solve () {
  ll w, n;
  cin >> w >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll m;
  cin >> m;
  vl b(m);
  rep(i, m) cin >> b[i];

  rep(i, m) {
    ll it = lower_bound(all(a), b[i] - w) - a.begin();
    if (it == a.size() || a[it] > b[i]) {
      cout << "no" << endl;
      return;
    }
    a.erase(a.begin() + it);
  }
  cout << "yes" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
