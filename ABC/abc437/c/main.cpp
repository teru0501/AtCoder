// abc437 C - Reindeer and Sleigh 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    ll w_sum = 0;
    ll p_sum = 0;
    ll  ans = 0;
    vector<tuple<ll, int, int>> wp(n);
    for (int i = 0; i < n; i++){
       ll w, p;
      cin >> w >> p;
      p_sum += p;
      wp[i] = {w + p, w, p};
    }
    sort (wp.begin(), wp.end());
    while (true){
      w_sum += get<1>(wp[ans]);
      p_sum -= get<2>(wp[ans]);
      if (w_sum <= p_sum)
        ans++;
      else
        break;
    }
    cout << ans << endl;
  }
}
