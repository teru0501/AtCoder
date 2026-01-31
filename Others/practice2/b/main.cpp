// practice2 B - Fenwick Tree
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> bit(n);
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    bit.add(i, a);
  }
  while (q--){
    int flg;
    cin >> flg;
    if (flg == 0){
      ll p, x;
      cin >> p >> x;
      bit.add(p, x);
    }
    else{
      int l, r;
      cin >> l >> r;
      cout << bit.sum(l, r) << endl;
    }
  }
}
