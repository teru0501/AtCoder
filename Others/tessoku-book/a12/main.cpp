// tessoku-book A12 - Printer
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

ll total(ll x, vector<int> a) {
    ll sum = 0;
    for (auto tmp : a) {
        sum += x / tmp;
    }
    return sum;
}

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
    ll left = 1;
    ll right = 1000000000;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (total(mid, a) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
  cout << left << endl;
  return 0;
}

