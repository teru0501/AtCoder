// tessoku-book A17 - Dungeon 2
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
#define IN(v) for (auto &x : (v)) cin >> x;
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

template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}


// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vi a(n + 1, 0);
  vi b(n + 1, 0);
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 3; i <= n; i++) cin >> b[i];
  vector<int> dp(100100, INT32_MAX);
  vector<int> prev(100100, -1);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (dp[i] > dp[i - 1] + a[i]) {
        dp[i] = dp[i - 1] + a[i];
        prev[i] = i - 1;
    }
    if (i >= 3 && dp[i] > dp[i - 2] + b[i]) {
        dp[i] = dp[i - 2] + b[i];
        prev[i] = i - 2;
    }
  }
  vector<int> ans;
  int cur = n;
  while (cur != -1) {
    ans.push_back(cur);
    cur = prev[cur];
  }
  reverse(all(ans));
  OUT(ans.size());
  VOUT(ans);
  return 0;
}
