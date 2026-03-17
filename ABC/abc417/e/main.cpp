// abc417 E - A Path in A Dictionary
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

vvl g;
vector<bool> vis;
vl ans;
ll n, m, x, y;
bool f = 0;

void dfs(ll v) {
	if (f) return;
	ans.push_back(v);
	vis[v] = 1;
	if (v == y) {
		rep(i, ans.size()) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << "\n";
		f = 1;
		return;
	}


	for (auto to : g[v]) {
		if (!vis[to]) {
			dfs(to);
			if (f) return;
		}
	}

	ans.pop_back();
}

void solve () {
  cin >> n >> m >> x >> y;

	f = 0;
	ans = {};
	g.assign(n + 1, {});
	vis.assign(n + 1, 0);

	rep(i, m) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	loop(i, 1, n) {
		sort(all(g[i]));
	}

	dfs(x);
  
  return;
}

// ---------------------- main ----------------------
int main() {
	ll t;
	cin >> t;
	while(t--)
  	solve();
  return 0;
}
