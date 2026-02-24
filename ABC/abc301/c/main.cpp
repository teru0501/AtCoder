#include <bits/stdc++.h>
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
  string s, t;
  cin >> s >> t;

  set<char> st;
  string t1 = "atcoder";
  for (auto c : t1) st.insert(c);

  unordered_map<char, ll> um1, um2;
  ll cnt1 = 0, cnt2 = 0;
  ll rem1 = 0, rem2 = 0;

  for (auto c : s) {
    if (c != '@') um1[c]++;
    else rem1++;
  }
  for (auto c : t) {
    if (c != '@') um2[c]++;
    else rem2++;
  }

  //  余ってる文字の数を数える
  for (auto [x, y] : um1) {
    if (y != um2[x] && !st.count(x)) {
      cout << "No" << endl;
      return;
    }
    else if (y > um2[x]) {
      cnt1 += y - um2[x];
    }
  }

  for (auto [x, y] : um2) {
    if (y != um1[x] && !st.count(x)) {
      cout << "No" << endl;
      return;
    }
    if (y > um1[x]) {
      cnt2 += y - um1[x];
    }
  }
  rem1 -= cnt2;
  rem2 -= cnt1;

  if (rem1 >= 0 && rem2 >= 0) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
