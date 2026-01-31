// tessoku-book B02 - Divisor Check
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int a, b;
  cin >> a >> b;
  int n = 100;
  for (int i = 1; i * i <= n; i++){
    if (n % i == 0){
      int x = n / i;
      int y = i;
      if ((x >= a && x <= b) || (y >= a && y <= b)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
