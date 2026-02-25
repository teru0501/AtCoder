// abc259 C - XX to XXX
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

vector<pair<char, int>> RLE(const string& s) {
  vector<pair<char, int>> res;
  res.reserve(s.size());
  for (auto tmp : s) {
    if (res.empty() || res.back().first != tmp) res.emplace_back(tmp, 1);
    else res.back().second++;
  }
  return res;
}

void solve () {
  string s, t;
  cin >> s >> t;
  auto a = RLE(s);
  auto b = RLE(t);

  if (a.size() != b.size()) {
    cout << "No" << endl;
    return;
  }

  ll sz = a.size();

  rep(i, sz) {
    bool f = 1;
    if (a[i].first != b[i].first) f = 0;
    else if (a[i].second < b[i].second) {
      if (a[i].second < 2) f = 0;
    }
    else if (a[i].second > b[i].second) f = 0;

    if (!f) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
