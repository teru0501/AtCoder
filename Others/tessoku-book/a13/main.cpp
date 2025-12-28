// tessoku-book A13 - Close Pairs
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &tmp : a){
    cin >> tmp;
  }
  for (int i = 0; i < n; i++){
    int left = 0, right = a.size() - 1; 
    while (left <= right) {
        int mid = (left + right) / 2;
        int dif = abs(a[mid] - a[i]);
        if (dif <= k)
            right = mid - 1;       // 見つかった
        else
            right = mid - 1;      // 左半分へ
    }
  }
  return 0;
}
