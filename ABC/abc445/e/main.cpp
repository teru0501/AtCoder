// abc445 E - Many LCMs
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

template<class T> size_t HashCombine(const size_t seed,const T &v){
    return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}
/* pair用 */
template<class T,class S> struct std::hash<std::pair<T,S>>{
    size_t operator()(const std::pair<T,S> &keyval) const noexcept {
        return HashCombine(std::hash<T>()(keyval.first), keyval.second);
    }
};

ll modpow(ll x, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}


unordered_map<pll, ll> mp;
vl b;
ll amari = 998244353;

void pf1 (ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll e = 0;
			while (n % i == 0) {
				e++;
        mp[{i, e}]++;
				n /= i;
			}
		}
	}
	if (n != 1) {
    mp[{n, 1}]++;
  }
}

void pf2 (ll n, ll v) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll e = 0;
      ll mx = 0;
			while (n % i == 0) {
				e++;
        if (mp[{i, e}] >= 2) mx = e;
				n /= i;
			}
      ll t = i % amari;
      b[v] *= max(ll(1), (t * (e - mx))) % amari;
      b[v] %= amari;
		}
	}
	if (n != 1) {
    if (mp[{n, 1}] == 1) {
      b[v] *= n % amari;
      b[v] %= amari;
    }
  }
  b[v] %= amari;
}

void solve () {
  ll n;
  cin >> n;
  vl a(n);
  b.assign(n, 1);
  rep(i, n) cin >> a[i];

  ll sum = a[0];
  loop(i, 1, n - 1) {
    sum = lcm(sum, a[i]);
  }

  rep(i, n) {
    pf1(a[i]);
  }

  rep(i, n) {
    pf2(a[i], i);
  }

  rep(i, n) {
    if (i) cout << " ";
    if (b[i] == 0) cout << sum % amari;
    else cout << sum * modpow(b[i], amari-2, amari) % amari;

  }
  cout << endl;
  return;
}

// ---------------------- main ----------------------
int main() {
  ll t;
  cin >> t;
  while(t--) {
    solve();
  }
  
  return 0;
}
