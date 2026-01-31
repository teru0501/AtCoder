// abc315 C - Flavors
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

//同じ種類を食べた時の最大値
//違う種類を食べた時の最大値

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vvll fs(n + 1, vll(2, -1));
  vll fsm(2, -1);
  ll ans = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (fs[a][0] < b) {
        fs[a][1] = fs[a][0];
        fs[a][0] = b;
    }
    else if (fs[a][1] < b) {
        fs[a][1] = b;
    }
  }
  for (const auto& tmp  : fs) {
    if (tmp[1] != -1) {
    ans = max(ans, tmp[0] + tmp[1] / 2);
    }  
    if (fsm[0] < tmp[0]) {
        fsm[1] = fsm[0];
        fsm[0] = tmp[0];
    }
    else if (fsm[1] < tmp[0]) {
        fsm[1] = tmp[0];
    }
  }
  if (fsm[1] != -1) {
    ans = max(fsm[0] + fsm[1], ans);
  }
  OUT(ans);
  return 0;
}
