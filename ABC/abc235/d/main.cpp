// abc235 D - Multiply and Rotate
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
const ll INF = 9223372036854775807LL;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;

// ================= UTILITY ================= //
bool in_grid(ll i, ll j, ll h, ll w) {return(0<=i&&i<h&&0<=j&&j<w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

// BFS?

void solve () {
  ll a, n;
  cin >> a >> n;

  vl dist(n * 10, -1);
  
  queue<ll> q;
  q.push(1);
  dist[1] = 0;

  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    // 操作A
    ll x = v * a;
    if (n * 9 >= x && dist[x] == -1) {
      dist[x] = dist[v] + 1;
      q.push(x);
    } 
    // 操作B
    string s = to_string(v);
    s = s.back() + s.substr(0, s.size() - 1);
    if (v % 10 == 0 || v < 10) continue;
    ll y = stoll(s); 
    if (n * 9 >= y && dist[y] == -1) {
      dist[y] = dist[v] + 1;
      q.push(y);
    } 
  }

  cout << dist[n] << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
