// typical90 001 - Yokan Party（★4）
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

// スコアXを決め打つ

bool fnc (ll x, ll n, ll k, vl& v) {
	ll cnt = 0;
	ll sum = 0;
	ll sz = v.size();
	rep(i, sz) {
		sum += v[i];
		if (sum >= x) {
			cnt++;
			sum = 0;
		}
	}
	if (cnt >= k + 1) return 1;
	else return 0;
}

void solve () {
  ll n, l, k;
  cin >> n >> l >> k;

  vl a(n);
  rep(i, n) cin >> a[i];

  vl v;
  if (a[0] != 0) v.push_back(a[0]);
  loop(i, 1, n - 1) {
    v.push_back(a[i] - a[i - 1]);
  }
  if (a[n - 1] != l) v.push_back(l - a[n - 1]);
  
  ll left = 0;
  ll right = INF;
	ll ans = 0;
  while(right - left > 1) {
    ll mid = (left + right) / 2;
    if (fnc(mid, n, k, v)) {
			left = mid;
			chmax(ans, left);
    }
		else {
			right = mid;
		}
  }
	cout << ans << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
