// tessoku-book A28 - Blackboard
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region TEMPLATE
// ================= TYPE ================= //
using ll = long long;

// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
using pic = pair<int, char>;
using psi = pair<string, int>;
using pis = pair<int, string>;
using pss = pair<string,string>;
using pcc = pair<char,char>;
// vector
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

// ================= MACRO ================= //
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define IN(v) for (auto &x : (v)) cin >> x;
#define OUT(x) cout << (x) << endl
#define VOUT(v) for(auto x : (v)) cout << x << " "; cout << endl
#define VVOUT(vv) for(auto &v : (vv)) VOUT(v)
#define rep0(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)

// ================= CONST ================= //
const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dx = {-1,0,1,1,1,0,-1,-1};
const int INF = 1e9;
const ll LINF = (ll)4e18;
const int MOD = 998244353;

// ================= UTILITY ================= //
bool out_grid(ll i, ll j, ll h, ll w) {
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
#pragma endregion

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  ll ans = 0;
  while(n--) {
    char t;
    int a;
    cin >> t >> a;
    if (t == '+') ans += a;
    else if (t =='-') ans -= a;
    else ans *= a;
    ans = (ans + 10000) % 10000;
    OUT(ans % 10000);
  }
  return 0;
}
