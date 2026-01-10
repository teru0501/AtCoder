// abc433 C - 1122 Substring 2
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//ランレングス圧縮してから一つ上がるところが見つかればその両端の数の小さいほうをcnt++

vector<pair<char, int>> RLE(string s)
{
    vector<pair<char, int>> ans;
    for (auto &x : s)
    {
        if (ans.empty())
            ans.push_back({x, 1});
        else if (ans[ans.size() - 1].first == x)
            ans[ans.size() - 1].second++;
        else
            ans.push_back({x, 1});
    }
    return ans;
}

int main() {
  string tmp;
  cin >> tmp;
  vector<pair<char, int>> s = RLE(tmp);
  int ans = 0;
  int n = s.size();
  for (int i = 0; i < n - 1; i++){
    int x1 = s[i].first - '0';
    int y1 = s[i].second;
    int x2 = s[i + 1].first - '0';
    int y2 = s[i + 1].second;
    if (x1 + 1 == x2){
      ans += min(y1, y2);
    }
  }
  cout << ans << endl;
}
