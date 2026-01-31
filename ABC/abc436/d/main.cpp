// abc436 D - Teleport Maze 
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

bool out_of(int x, int y, int h, int w){
    return x < 0 || x >= h || y < 0 || y >= w;
}

// テレポートの情報をunorderd_setに入れる。
// BFSを使う。
// 壁がなかったらそこを

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  unordered_map<char, vector<pair<int, int>>> tp;
  vector<vector<int>> dist(h, vector<int>(w, -1));
  for (auto &tmp : s)
    cin >> tmp;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (s[i][j] != '#' && s[i][j] != '.')
        tp[s[i][j]].push_back({i, j});

  queue<pair<int, int>> q;
  q.push({0 , 0});
  dist[0][0] = 0;
  while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    //ゴール処理
    if (cx == h - 1 && cy == w - 1){
      cout << dist[cx][cy] << endl;
      return 0;
    }

    // ワープ処理
    if (s[cx][cy] != '.'){
      for (auto [wx, wy] : tp[s[cx][cy]]){
        if (cx != wx || cy != wy){
          if (dist[wx][wy] == -1){
            q.push({wx, wy});
            dist[wx][wy] = dist[cx][cy] + 1;
          }
        }
      }
       tp.erase(s[cx][cy]);
    }

    // 移動処理
    for (int i = 0; i < 4; i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (!out_of(nx, ny, h, w)){
        if (s[nx][ny] != '#' && dist[nx][ny] == -1){
          q.push({nx, ny});
          dist[nx][ny] = dist[cx][cy] + 1;
        }
      }
    }
  }
  cout << -1 << endl;
}
