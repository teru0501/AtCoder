// abs ABC086A - Product
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a * b;
  if (ans % 2 == 0)
    cout << "Even" << endl;
  else
    cout << "Odd" << endl;
}
