// tessoku-book B39 - Taro's Job
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
// 
// ============================================ //

void solve () {
  ll n, d;
  cin >> n >> d;
  ll t = 0; // 今何日目か
  unordered_map<ll, vll> jobs; // i日目の仕事
  vll st; // 何日目から仕事が始まるか
  rep0 (i, n) {
    ll x, y;
    cin >> x >> y;
    st.push_back(x);
    jobs[x].push_back(y);
  }
  st.erase(unique(st.begin(), st.end()), st.end());
  sort(all(st));
  for (auto& [_, tmp] : jobs) {
    sort(rall(tmp));
  }
  ll m = st.size();
  ll ans = 0;
  rep0 (i, m) {
    ll sz = jobs[st[i]].size();
    if (t < st[i]) t = st[i];
    rep0 (j, sz) {
      // もし次の日の仕事のほうがよかったらとばす
      if (t == st[i + 1]) {
        if (jobs[st[i + 1]][0] > jobs[st[i]][j]) {
          break;
        }
        t++;
        ans += jobs[st[i]][j];
      }
      else {
        t++;
        ans += jobs[st[i]][j];
      }
    }
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
