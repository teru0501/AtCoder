// abc423 C - Lock All Doors 
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;
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
//const vi dx = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0 <= i && i < h && 0 <= j && j < w);}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

// その部屋から両方向に両端の空いているところまで探索してカウントしていく

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  ll n, r;
  cin >> n >> r;
  vll l(n);
  ll f = INF;
  ll s = -1;
  rep0 (i, n) {
    cin >> l[i];
    if (l[i] == 0) {
        f = min(f, i);
        s = max(s, i);
    }
  }
  if (f == INF && s == -1) {
    OUT(0);
    return 0;
  }
  ll ans = 0;
  
  for (ll i = r - 1; i >= f; i--) {
    if (l[i] == 1) ans++;
  }
  ans += max(r - f, ll(0));
  for (ll i = r; i <= s; i++) {
    if (l[i] == 1) ans++;
  }
  ans += max(s - r + 1, ll(0));
  OUT(ans);
  return 0;
}
