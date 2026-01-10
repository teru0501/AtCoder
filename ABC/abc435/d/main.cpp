// abc435 D - Reachability Query 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//FからTに変わった場合のみBFS

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> black(n + 1, 0);
  vector<vector<int>> g(n + 1);
  while(m--){
    int x, y;
    cin >> x >> y;
    g[y].push_back(x);
  }
  int x;
  cin >> x;
  while(x--){
    int flg, v;
    cin >> flg >> v;
    if (flg == 1){
      if (!black[v]){
        queue<int> q;
        black[v] = 1;
        q.push(v);
        while(!q.empty()){
          int cur = q.front();
          q.pop();
          for (auto nxt : g[cur]){
            if (!black[nxt]){
              black[nxt] = 1;
              q.push(nxt);
            }
          }
        }
      }
    }
    else if (black[v])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
