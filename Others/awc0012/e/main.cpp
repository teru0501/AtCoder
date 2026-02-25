// awc0012 E - Stone Crossing Game
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

template<class T>
struct SegTree { // 0-indexed, 半開区間 [l, r)
    ll n = 1;
    vector<T> seg;
    T ID;
    T (*op)(T, T);
    
    // 完全二分木にする＆初期化
    SegTree(ll _n, T _ID, T (*_op)(T, T)) : ID(_ID), op(_op) {
        while (n < _n) n *= 2;
        seg.assign(n * 2, ID);
    }
    
    // 更新
    void set(ll i, T x) {
        ll idx = i + n;
        seg[idx] = x;
        idx /= 2;
        while (idx > 0) {
          seg[idx] = op(seg[idx * 2], seg[idx * 2 + 1]);
          idx /= 2;
        }
    }
    
    // クエリ処理
    T query(ll l, ll r) {
        l += n;
        r += n;
        T res = ID;
        while(l < r) {
          if (l % 2 == 1) {
            res = op(res, seg[l]);
            l++;
          }
          if (r % 2 == 1) {
            res = op(res, seg[r - 1]);
            r--;
          }
          l /= 2, r /= 2;
        }
        return res;
    }
};

ll op(ll a, ll b) {
  return max(a, b);
}


void solve () {
  ll n, k;
  cin >> n >> k;

  vl a(n + 1);

  SegTree seg(n, -INF, op);
  loop(i, 1, n) {
    cin >> a[i];
  }

  vl dp(n + 1);
  dp[1] = a[1];
  seg.set(0, dp[1]);

  loop(i, 2, n) {
    ll left = max(i - k - 1, 0LL);
    ll right = i - 2;
    ll mn = seg.query(left, right + 1);
    dp[i] = mn + a[i];
    seg.set(i - 1, dp[i]);
  }

  cout << dp[n] << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
