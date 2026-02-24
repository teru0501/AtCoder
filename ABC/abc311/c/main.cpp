// abc311 C - Find it!
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

void solve () {
  ll n;
  cin >> n;
  
  vl a(n + 1);
  vector<bool> vis(n + 1, 0);
  loop(i, 1, n) cin >> a[i];

  loop(i, 1, n) {
    if (vis[i]) continue;
    ll now = i;
    vl ans;
    set<ll> st;

    vis[now] = 1;
    ans.push_back(now);
    st.insert(now);

    while(true) {
      now = a[now];
      vis[now] = 1;
      if (st.count(now)) {
        ll pos = 0;
        while(ans[pos] != now) pos++;
        ll sz = ans.size();
        cout << sz - pos<< endl;
        loop(j, pos, sz - 1) {
          if (j != pos) cout << " ";
          cout << ans[j];
        }
        cout << endl;
        return;
      }
      else {
        ans.push_back(now);
        st.insert(now);
      } 
    }
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
