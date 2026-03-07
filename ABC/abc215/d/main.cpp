// abc215 D - Coprime 2
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

void prime_factorize (ll n, vector<bool>& sum) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll e = 0;
			while (n % i == 0) {
				e++;
				n /= i;
			}
      if (i < (ll)sum.size()) sum[i] = 0;
		}
	}
	if (n != 1 && n < (ll)sum.size()) sum[n] = 0;
}

void solve () {
  ll n, m;
  cin >> n >> m;

  vector<bool> sum(m + 1, 1);
  vector<bool> ans(m + 1, 1);
  ll cnt = 1;

  rep(i, n) {
    ll a;
    cin >> a;
    prime_factorize(a, sum);
  }

  for (ll i = 2; i <= m; i++) {
    if (!sum[i]) {
      ans[i] = 0;
      for (ll j = i; j <= m; j += i) {
        ans[j] = 0;
      }
    }
    
    if (ans[i]) cnt++;
  }

  cout << cnt << "\n";
  loop(i, 1, m) if (ans[i]) cout << i << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
