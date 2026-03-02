// abc314 D - LOWER
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
  ll n, q;
  string s;
  cin >> n >> s >> q;
  
  set<ll> up;
  set<ll> low;

	//逆転が発生してるか？
	bool f1 = 0; 
	bool f2 = 0; 

  rep(i, n) {
    if (isupper(s[i]))  {
			up.insert(i);
    }
		else {
			low.insert(i);
		}
  }

  while(q--) {
    ll t, x;
		char c;
		cin >> t >> x >> c;
		x--;
		if (t == 1) {
			if (isupper(s[x])) up.erase(x);
			else low.erase(x);
			s[x] = c;
			if (isupper(s[x])) up.insert(x);
			else low.insert(x);
		}
		else if (t == 2) {
			if (!f1) f1 = !f1;
			if (f2) f2 = !f2;
		}
		else {
			if (f1) f1 = !f1;
			if (!f2) f2 = !f2; 
		}
  }

	rep(i, n) {
		if (up.count(i) && f1) {
			s[i] = tolower(s[i]);
		}
		else if (low.count(i) && f2) {
			s[i] = toupper(s[i]);
		}
	}

	cout << s << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
