// abc431 C - Robot Factory
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//頭も体も昇順
//勝つための最低限の体から貪欲

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> h(n);
  vector<int> b(m);
  for (auto &tmp : h){
    cin >> tmp;
  }
  for (auto &tmp : b){
    cin >> tmp;
  }
  sort(h.begin(), h.end());
  sort(b.begin(), b.end());
  int p =  m - k;
  for (int i = 0; i < k; i++){
    if (h[i] > b[p + i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
