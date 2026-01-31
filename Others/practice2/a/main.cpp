// practice2 A - Disjoint Set Union
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n, q;
  cin >> n >> q;
  dsu uf(n);
  while (q--){
    int flg, u, v;
    cin >> flg >> u >> v;
    if (flg == 0)
      uf.merge(u, v);
    else if (uf.same(u, v)){
      cout << 1 << endl;
    }
    else
      cout << 0 << endl;
  }
}
