// awc0001 E - Temperature Fluctuation Range
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

// 累積maxとminを取得
// seg木？

struct SegTreeMx { // 0-indexed, 半開区間 [l, r)
    ll n = 1;
    vector<ll> seg;
    ll ID = -INF; // 最大値
    
    // 完全二分木にする＆初期化
    SegTreeMx(int _n) {
        while (n < _n) n *= 2;
        seg.assign(n * 2, ID);
    }
    
    // 演算処理
    ll op(ll a, ll b) {
        return max(a, b); // 最大値
    }
    
    // 更新
    void set(ll i, ll x) {
        ll idx = i + n;
        seg[idx] = x;
        idx /= 2;
        while (idx >= 1) {
          seg[idx] = op(seg[idx * 2], seg[idx * 2 + 1]);
          idx /= 2;
        }
    }
    
    // クエリ処理
    ll query(ll l, ll r) {
        l += n;
        r += n;
        ll res = ID;
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

struct SegTreeMi { // 0-indexed, 半開区間 [l, r)
    ll n = 1;
    vector<ll> seg;
    ll ID = INF; // 最小値
    
    // 完全二分木にする＆初期化
    SegTreeMi(int _n) {
        while (n < _n) n *= 2;
        seg.assign(n * 2, ID);
    }
    
    // 演算処理
    ll op(ll a, ll b) {
        return min(a, b); // 最小値
    }
    
    // 更新
    void set(ll i, ll x) {
        ll idx = i + n;
        seg[idx] = x;
        idx /= 2;
        while (idx >= 1) {
          seg[idx] = op(seg[idx * 2], seg[idx * 2 + 1]);
          idx /= 2;
        }
    }
    
    // クエリ処理
    ll query(ll l, ll r) {
        l += n;
        r += n;
        ll res = ID;
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


void solve () {
  ll n, k;
  cin >> n >> k;

  SegTreeMx segmx(n);
  SegTreeMi segmi(n);
  vl h(n);
  rep(i, n) {
    cin >> h[i];
    segmx.set(i, h[i]);
    segmi.set(i, h[i]);
  }

  ll ans = -1;
  loop(i, 0, n - k) {
    ll l = i, r = i + k;
    ll tmp = abs(segmx.query(l, r) - segmi.query(l, r));
    chmax(ans, tmp);
  }
  cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
