// abc076 C - Dubious Document 2
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

// 文字列の後ろから共通する部分文字列を探していく。
// 発見したら、?をすべてaとして出力

void solve () {
  string s, t;
  cin >> s >> t;
  ll n = s.length();
  ll m = t.length();
  string ans = s;

  for (int i = n; i >= m; i--) {
    string sub = s.substr(i - m, m);
    bool ok = 1;
    rep(j, m) {
      if (sub[j] != t[j] && sub[j] != '?') ok = 0;
    }
    if (!ok) continue;
    ans.replace(i - m, m, t);
    for (auto& tmp : ans) {
      if (tmp == '?') tmp = 'a';
    }
    cout << ans << endl;
    return;
  }
  cout << "UNRESTORABLE" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
