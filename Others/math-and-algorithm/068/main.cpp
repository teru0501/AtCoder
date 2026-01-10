// math-and-algorithm 068 - Number of Multiples 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
using pic = pair<int, char>;
using psi = pair<string, int>;
using pis = pair<int, string>;

using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;

using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define IN(v) for (auto &x : (v)) cin >> x;
#define OUT(x) cout << (x) << endl
#define rep0(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rep_range(i, l, r) for (int i = (l); i < (r); ++i)

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
  
  return 0;
}
