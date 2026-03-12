// typical90 012 - Red Painting（★4）
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
bool in_grid(ll i, ll j, ll h, ll w) {return(1<=i&&i<=h&&1<=j&&j<=w);}
template<typename T> bool chmin(T& a, T b){if(a>b){a=b; return 1;} return 0;}
template<typename T> bool chmax(T& a, T b){if(a<b){a=b; return 1;} return 0;}
auto _ = []{ios::sync_with_stdio(false); cin.tie(nullptr); cout<<setprecision(12)<<fixed; return 0;}();
#pragma endregion

struct UnionFind
{
  vl p, sz;

  UnionFind(ll n) {
    p.assign(n + 1, -1);
    sz.assign(n + 1, 1);
  }

  ll root(ll x) {
    if (p[x] == -1) return x;
    return p[x] = root(p[x]);
  }

  void unite(ll _a, ll _b) {
    ll a = root(_a);
    ll b = root(_b);

    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
  }

  bool same(ll u, ll v) {
    return root(u) == root(v);
  }
};

ll conv(ll h, ll w) {
	return h + w * 10000;
}

void solve () {
  ll h, w;
  cin >> h >> w;
  UnionFind uf(conv(h, w) + 1);

  set<ll> st;
  ll q;
  cin >> q;
  while(q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll r, c;
			cin >> r >> c;
			st.insert(conv(r, c));
			rep(i, 4) {
				ll nr = r + dx[i];
				ll nc = c + dy[i];
				if (in_grid(nr, nc, h, w)) {
					if (st.count(conv(nr, nc)))
						uf.unite(conv(r, c), conv(nr, nc));
				}
			}
    }
		else {
			ll r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			if (st.count(conv(r1, c1)) && st.count(conv(r2, c2))) {
				if (uf.same(conv(r1, c1), conv(r2, c2))) cout << "Yes" << "\n";
				else cout << "No" << "\n";
			}
			else cout << "No" << "\n";
		}
  }
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
