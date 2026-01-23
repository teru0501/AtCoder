// abc432 B - Permute to Minimize
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//SWAPする

int main() {
  cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
  
  string s;
  cin >> s;
  int n = s.length();
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++){
    if (s[i] != '0'){
      swap(s[i], s[0]);
      break;
    }
  }
  cout << s << endl;
  return 0;
}
