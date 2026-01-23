// abc314 C - Rotate Colored Subsequence
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
#define rep1(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,n) for(int i = 1; i <= (n); ++i)

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

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> num(m + 1);
  vector<vector<char>> mozi(m + 1);
  string s;
  cin >> s;
  rep2 (i, n) {
    int c;
    cin >> c;
    num[c].push_back(i);
    mozi[c].push_back(s[i - 1]);
  }
  rep2 (i, m) {
    num[i].push_back(num[i][0]);
    num[i].erase(num[i].begin());
  }
  string ans(n, '?');
  rep2 (i, m) {
    rep1 (j, num[i].size()) {
        ans[num[i][j] - 1] = mozi[i][j];
    }
  }
  OUT(ans);
  return 0;
}
