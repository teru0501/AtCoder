// abc428 C - Brackets Stack Query
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

// ---------------------- main ----------------------
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(12) << fixed;

  int q;
  cin >> q;
  stack<char> st; // (を追加
  stack<char> que; // )を追加
  stack<int> DO;
  int last;
  while(q--) {
    int f;
    cin >> f;
    if (f == 1) {
        char c;
        cin >> c;
        if (c == '(') {
            st.push(c);
            DO.push(0);
        }
        else {
            if (!st.empty()) {
                st.pop();
                DO.push(1);
            }
            else {
                que.push(c);
                DO.push(2);
            }
        }
    }
    else {
        if (DO.top() == 0) st.pop();
        if (DO.top() == 1) st.push('(');
        if (DO.top() == 2) que.pop();
        DO.pop();
    }
    if (st.empty() && que.empty()) YES;
    else NO;
  }
  return 0;
}
