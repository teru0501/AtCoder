// awc0009 D - Planting Flower Seeds
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

// 区間をsetで管理する

void add_interval(set<pll>& st, ll l, ll r) {

    auto it = st.lower_bound({l, -INF});

    // 1つ前もチェック
    if (it != st.begin()) {
        --it;
    }

    vector<pll> erase_list;

    while (it != st.end()) {
        auto [L, R] = *it;

        // 重ならないなら終了
        if (R < l || r < L) {
            if (L > r) break;
            ++it;
            continue;
        }

        // マージ
        l = min(l, L);
        r = max(r, R);

        erase_list.push_back(*it);
        ++it;
    }

    // 消す
    for (auto& p : erase_list) {
        st.erase(p);
    }

    // 入れる
    st.insert({l, r});
}


void solve () {
  ll n, m;
  cin >> n >> m;

  set<pll> st;

  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    add_interval(st, l, r);
  }

  ll ans = 0;
  ll now = 1;

  for (auto [x, y] : st) {
    ans += x - now;
    now = y + 1;
    if (n <= ans) {
      cout << x - 1 - (ans - n) << endl;
      return;
    }
  }
  now += n - ans - 1;

  cout << now << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
