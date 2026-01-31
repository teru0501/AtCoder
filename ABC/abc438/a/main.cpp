// abc438 A - First Contest of the Year
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;


int main() {
  int d, f;
  cin >> d >> f;
  while (true){
    f += 7;
    if (d < f){
      cout << f - d << endl;
      return 0;
    }
  }
}
