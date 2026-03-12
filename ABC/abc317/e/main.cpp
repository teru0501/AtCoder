// abc317 E - Avoid Eye Contact
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

// 上下左右

void solve () {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vvl g(h, vl(w, 1));

  ll now = 1;
  
  //　左から
  rep(i, h) {
    ll j = 0;
    while(j < w) {
      if (s[i][j] == '>') now = 0;
			else if (s[i][j] != '.') now = 1;

			if (!g[i][j]) {}
			else if (s[i][j] == 'S' || s[i][j] == 'G') {}
			else if (s[i][j] != '.') g[i][j] = 0;
			else g[i][j] = now;
			j++;
    }
		now = 1;
  }

	// 右から
  rep(i, h) {
    ll j = w - 1;
    while(j >= 0) {
      if (s[i][j] == '<') now = 0;
			else if (s[i][j] != '.') now = 1;

			if (!g[i][j]) {}
			else if (s[i][j] == 'S' || s[i][j] == 'G') {}
			else if (s[i][j] != '.') g[i][j] = 0;
			else g[i][j] = now;
			j--;
    }
		now = 1;
  }

	// 上から
  rep(j, w) {
    ll i = 0;
    while(i < h) {
      if (s[i][j] == 'v') now = 0;
			else if (s[i][j] != '.') now = 1;

			if (!g[i][j]) {}
			else if (s[i][j] == 'S' || s[i][j] == 'G') {}
			else if (s[i][j] != '.') g[i][j] = 0;
			else g[i][j] = now;
			i++;
    }
		now = 1;
  }

	// 下から
  rep(j, w) {
    ll i = h - 1;
    while(i >= 0) {
      if (s[i][j] == '^') now = 0;
			else if (s[i][j] != '.') now = 1;

			if (!g[i][j]) {}
			else if (s[i][j] == 'S' || s[i][j] == 'G') {}
			else if (s[i][j] != '.') g[i][j] = 0;
			else g[i][j] = now;
			i--;
    }
		now = 1;
  }

	ll sx, sy, gx, gy;
	rep(i, h) rep(j, w) {
		if (s[i][j] == 'S') sx = i, sy = j;
		else if (s[i][j] == 'G') gx = i, gy = j;
	}

	queue<pll> q;
	q.push({sx, sy});
	vvl dist(h, vl(w, -1));
	dist[sx][sy] = 0;

	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		rep(i, 4) {
			ll nx = x + dx[i];
			ll ny = y + dy[i];
			if (in_grid(nx, ny, h, w)) {
				if (g[nx][ny] && dist[nx][ny] == -1) {
					q.push({nx, ny});
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}

	cout << dist[gx][gy] << "\n";
  return;
}

// ---------------------- main ----------------------
int main() {
  solve();
  return 0;
}
