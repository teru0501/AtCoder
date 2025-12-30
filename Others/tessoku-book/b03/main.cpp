// tessoku-book B03 - Supermarket 1
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//二重ループしてハッシュ

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &tmp : a){
    cin >> tmp;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (i != j && i != k && j != k)
          if (a[i] + a[j] + a[k] == 1000){
            cout << "Yes" << endl;
            return 0;
          }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
