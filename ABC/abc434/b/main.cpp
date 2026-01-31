// abc434 B - Bird Watching
#include <bits/stdc++.h>
#include <atcoder/all>
# include <iomanip>
using namespace std;
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> mp;
  while (n--){
    int a, b;
    cin >> a >> b;
    mp[a].push_back(b);
  }
  for (auto [x, y] : mp){
    double sum = 0;
    for (auto z : y){
      sum += z;
    }
    double avg = sum / y.size();
    cout << fixed << setprecision(15) << avg << endl;
  }
}
