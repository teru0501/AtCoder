// abc213 C - Reorder Cards
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define OUT(x) cout << (x) << endl
#define rep1(i,n) for(ll i = 0; i < (n); ++i)
#define rep2(i,n) for(ll i = 1; i <= (n); ++i)

const vi dx = {-1,0,1,0};
const vi dy = {0,1,0,-1};
//const vi dx = {-1,-1,-1,0,1,1,1,0};
//const vi dx = {-1,0,1,1,1,0,-1,-1};

bool out_grid(ll i, ll j, ll h, ll w) {
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

template <class T>
void VOUT(const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

template <class T>
void VVOUT(const vector<vector<T>>& vv) {
    for (const auto& v : vv) {
        VOUT(v);
    }
}

//まずvectorにa, bを登録　それぞれ縦と横で別々にいれて
//ソートしたもののindexがその列になる。
//ansにその結果を保存

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  ll h, w, n;
  cin >> h >> w >> n;
  vector<pll> x;
  vector<pll> y;
  rep2 (i, n) {
    ll a, b;
    cin >> a >> b;
    x.push_back({a, i});
    y.push_back({b, i});
  }
  sort(all(x));
  sort(all(y));
  vector<pll> ans(n + 1);
  rep1 (i, n) {
    ans[x[i].second].first = i + 1;
  }
  rep1 (i, n) {
    ans[y[i].second].second = i + 1;
  }
  rep2 (i, n) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
