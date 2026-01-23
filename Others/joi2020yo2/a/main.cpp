// joi2020yo2 A - ポスター (Poster)
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
// 色確認→回転を左右2回ずつ
// ============================================ //

ll check_vv(vector<string>& s, vector<string>& t) {
    ll res = 0;
    rep0 (i, s.size()) {
        rep0 (j, s[0].size()) {
            if (s[i][j] != t[i][j]) res++;
        }
    }
    return res;
}

vector<string> rotate90(const vector<string>& a, bool CW) {
    int h = a.size();
    int w = a[0].size();
    vector<string> b(w, string(h, '.'));

    rep0(i, h) rep0(j, w) {
        if (CW) b[j][h - 1 - i] = a[i][j];
        else    b[w - 1 - j][i] = a[i][j];
    }
    return b;
}

void solve () {
  int n;
  cin >> n;
  ll ans = LINF;
  vector<string> s(n);
  vector<string> t(n);
  IN(s);
  IN(t);

  vector<string> s1 = s;

  ans = min(check_vv(s, t), ans); 

  // 時計回り
  rep1 (i, 2) {
    s = rotate90(s, 1);
    ans = min(check_vv(s, t) + i, ans); 
  }
  // 反時計回り
  s = s1;
  rep1 (i, 2) {
    s = rotate90(s, 0);
    ans = min(check_vv(s, t) + i, ans); 
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
