// abc436 A - o-padding
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n;
  string s;
  cin >> n >> s;
  string add(n - s.length(), 'o');
  cout << add <<  s << endl;
}
