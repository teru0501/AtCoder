// abc399 B - Ranking with Ties
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
  vector<pair<int, int>> p(n + 1, {0, 0});
  vi ans(n + 1);
  rep2 (i, n) {
    int tmp;
    cin >> tmp;
    p[i] = {tmp, i};
  }
  sort(rall(p));
  int cnt = 0;
  int d = 0;
  rep1 (i, n) {
    if (p[i].first != p[i - 1].first) {
        cnt += 1 + d;
        d = 0;
    } 
    else d++;
    ans[p[i].second] = cnt;
  }
  rep2 (i, n) OUT(ans[i]);
  return 0;
}
