// practice2 J - Segment Tree
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

struct SegTree { // 0-indexed
    ll n = 1;
    vector<ll> seg;
    ll ID = -INF;

    SegTree(int _n) {
        while (n < _n) n *= 2;
        seg.assign(n * 2, ID);
    }

    ll op(ll a, ll b) {
        return max(a, b); // 最大値
    }

    void set(ll i, ll x) {
        ll idx = i + n;
        seg[idx] = x;
        idx /= 2;
        while (idx >= 1) {
          seg[idx] = op(seg[idx * 2], seg[idx * 2 + 1]);
          idx /= 2;
        }
    }

    ll query(ll l, ll r) {
        l += n;
        r += n;
        ll res = -INF;
        while(l < r) {
          if (l % 2 == 1) {
            chmax(res, seg[l]);
            l++;
          }
          if (r % 2 == 1) {
            chmax(res, seg[r - 1]);
            r--;
          }
          l /= 2, r /= 2;
        }
        return res;
    }
};


void solve () {
  ll n, q;
  cin >> n >> q; 
  SegTree seg(n);
  loop(i, 1, n) {
    ll a;
    cin >> a;
    seg.set(i, a);
  }
  while(q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll x, v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
    }
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
