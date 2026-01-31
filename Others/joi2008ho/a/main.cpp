// joi2008ho A - 碁石ならべ
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define IN(v) for (auto &x : (v)) cin >> x;
#define OUT(x) cout << (x) << endl
#define VOUT(v) do { for(auto x : (v)) cout << x << " "; cout << endl; } while(0)
#define VVOUT(vv) do { for(auto &v : (vv)) VOUT(v); } while(0)
#define rep0(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

// ================= CONST ================= //
const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dy = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0 <= i && i < h && 0 <= j && j < w);}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

// ================= STRATEGY ================= //
// 制約をみろ！！
// 愚直を考えろ！！
// オバフロ注意！！
// 偶数の場合と奇数の場合を考える
// <奇数> 置き換えずにPUSH
// <偶数>
// 1. 同じ場合は 置き換えずにPUSH
// 2. 違う場合は 色を反転させてPUSH
// ============================================ //

stack<pii> st;

void PUSH (int a) {
  pii tmp = st.top();
  st.pop();
  tmp.second += a;
  st.push(tmp);
}

void solve () {
  int n;
  cin >> n;

  rep1 (i, n) {
    int c;
    cin >> c;
    if (i % 2 == 1) {
      if (!st.empty() && st.top().first == c) PUSH(1);
      else st.push({c, 1});
    }
    else {
      if (st.top().first == c) {
        if (!st.empty() && st.top().first == c) PUSH(1);
        else st.push({c, 1});
      }
      else {
        pii tmp = st.top();
        st.pop();
        tmp.second++;
        tmp.first = tmp.first == 1 ? 0 : 1;
        if (!st.empty() && st.top().first == tmp.first) PUSH(tmp.second);
        else st.push(tmp);

      }
    }
  }
  int ans = 0;
  while (!st.empty()) {
    if (st.top().first == 0) ans += st.top().second;
    st.pop();
  } 
  OUT(ans);
  return;
}

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  solve();
  return 0;
}
