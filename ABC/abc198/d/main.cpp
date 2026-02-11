// abc198 D - Send More Money
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


// アルファベットの種類が10以上の場合はだめ
// それぞれのアルファベットに数字を割り当てる
// char -> int

void solve () {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  set<char> st;
  for (auto tmp : s1) st.insert(tmp);
  for (auto tmp : s2) st.insert(tmp);
  for (auto tmp : s3) st.insert(tmp);

  if (st.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return;
  }


  vector<char> v(all(st));
  ll n = v.size();
  unordered_map<char, ll> um;
  vl np(10);
  rep(i, 10) np[i] = i;

  do {
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    // umに変換
    rep(i, n) um[v[i]] = np[i];

    if (um[s1[0]] == 0 || um[s2[0]] == 0 || um[s3[0]] == 0) {
      continue;
    }
    // 十進法に変換
    rep(i, s1.size()) {
      if (i) sum1 *= 10;
      sum1 += um[s1[i]];
    }
    rep(i, s2.size()) {
      if (i) sum2 *= 10;
      sum2 += um[s2[i]];
    }
    rep(i, s3.size()) {
      if (i) sum3 *= 10;
      sum3 += um[s3[i]];
    }
    // 満たしていたら出力
    if (sum1 + sum2 == sum3) {
      cout << sum1 << endl;
      cout << sum2 << endl;
      cout << sum3 << endl;
      return;
    }
  } while(next_permutation(all(np)));
  cout << "UNSOLVABLE" << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
