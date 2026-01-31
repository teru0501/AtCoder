// tessoku-book A02 - Linear Search
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &tmp : a){
    cin >> tmp;
    if (tmp == x){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
