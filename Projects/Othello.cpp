#include <bits/stdc++.h>
using namespace std;

#define VOUT(v) do { for(auto x : (v)) cout << x << " "; cout << endl; } while(0)
#define VVOUT(vv) do { for(auto &v : (vv)) VOUT(v); } while(0)

/*
構築案
➤入力をうけとる
➤探索アルゴリズム開始
〇書き換えアルゴリズム開始
➤盤面を更新
➤入力にもどる
※TURN = 1、黒　TURN = 0、白とする
*/

vector<vector<string>> grid(9, vector<string>(9, "."));
vector<char> line;
bool turn = 1;
string me, you;
int u_cnt = 0;
int d_cnt = 0;
int l_cnt = 0;
int r_cnt = 0;
int lu_cnt = 0;
int ru_cnt = 0;
int ld_cnt = 0;
int rd_cnt = 0;

void displayBoard() {
    // ANSIカラーコード
    string cyan = "\033[36m";
    string green = "\033[32m";
    string yellow = "\033[33m";
    string white = "\033[97m";
    string gray = "\033[90m";
    string bg_white = "\033[47m";
    string bg_gray = "\033[40;1m";
    string bg_green = "\033[42m";
    string reset = "\033[0m";
    string bold = "\033[1m";
    
    cout << endl;
    
    // タイトル（カラフルに）
    cout << cyan << "  ___  _____ _   _ _____ _     _     ___  " << reset << endl;
    cout << green << " / _ \\|_   _| | | | ____| |   | |   / _ \\ " << reset << endl;
    cout << yellow << "| | | | | | | |_| |  _| | |   | |  | | | |" << reset << endl;
    cout << "\033[35m" << "| |_| | | | |  _  | |___| |___| |__| |_| |" << reset << endl;
    cout << "\033[31m" << " \\___/  |_| |_| |_|_____|_____|_____\\___/ " << reset << endl;
    cout << endl;
    
    // 上部の列番号
    cout << "    ";
    for (int j = 1; j <= 8; j++) {
        cout << "  " << bold << cyan << j << reset << "  ";
    }
    cout << endl;
    
    // 上部の罫線
    cout << "  ╔";
    for (int j = 1; j <= 8; j++) {
        cout << "════";
        if (j < 8) cout << "╤";
    }
    cout << "╗" << endl;
    
    for (int i = 1; i <= 8; i++) {
        // 行番号と盤面
        cout << bold << cyan << i << reset << " ║";
        
        for (int j = 1; j <= 8; j++) {
            string cell = grid[i][j];
            
            if (cell == "○" || cell == "o" || cell == "O") {
                // 白石
                cout << bg_green << " " << bg_white << "  " << reset << bg_green << " " << reset;
            } else if (cell == "●" || cell == "*") {
                // 黒石（グレーの背景で見やすく）
                cout << bg_green << " " << bg_gray << "  " << reset << bg_green << " " << reset;
            } else {
                // 空きマス
                cout << bg_green << "    " << reset;
            }
            
            if (j < 8) cout << "│";
        }
        
        cout << "║" << endl;
        
        // 行の区切り線
        if (i < 8) {
            cout << "  ╟";
            for (int j = 1; j <= 8; j++) {
                cout << "────";
                if (j < 8) cout << "┼";
            }
            cout << "╢" << endl;
        }
    }
    
    // 下部の罫線
    cout << "  ╚";
    for (int j = 1; j <= 8; j++) {
        cout << "════";
        if (j < 8) cout << "╧";
    }
    cout << "╝" << endl;
    cout << endl;
}
// 更新
void UPDATE () {
  system("clear");
  displayBoard();
}

// 置き換え
void REPLACE(int x, int y) {
    // 上方向
    for(int i = 1; i <= u_cnt; i++) grid[x-i][y] = me;

    // 下方向
    for(int i = 1; i <= d_cnt; i++) grid[x+i][y] = me;

    // 左方向
    for(int i = 1; i <= l_cnt; i++) grid[x][y-i] = me;

    // 右方向
    for(int i = 1; i <= r_cnt; i++) grid[x][y+i] = me;

    // 左上
    for(int i = 1; i <= lu_cnt; i++) grid[x-i][y-i] = me;

    // 右上
    for(int i = 1; i <= ru_cnt; i++) grid[x-i][y+i] = me;

    // 左下
    for(int i = 1; i <= ld_cnt; i++) grid[x+i][y-i] = me;

    // 右下
    for(int i = 1; i <= rd_cnt; i++) grid[x+i][y+i] = me;

    // 置いたマス自身
    grid[x][y] = me;
}

// 探索
bool SEARCH (int x, int y) {
  bool f = 0;

  //上方向
  u_cnt = 0;
  for (int i = x - 1; i >= 0; i--) {
    if (grid[i][y] == you) u_cnt++;
    else if (grid[i][y] == me) break;
    else {
      u_cnt = 0;
      break;
    }
  }
  if (u_cnt != 0) f = 1;

  //下方向
  d_cnt = 0;
  for (int i = x + 1; i <= 8; i++) {
    if (grid[i][y] == you) d_cnt++;
    else if (grid[i][y] == me) break;
    else {
      d_cnt = 0;
      break;
    }
  }
  if (d_cnt != 0) f = 1;

  //左方向
  l_cnt = 0;
  for (int i = y - 1; i >= 0; i--) {
    if (grid[x][i] == you) l_cnt++;
    else if (grid[x][i] == me) break;
    else {
      l_cnt = 0;
      break;
    }
  }
  if (l_cnt != 0) f = 1;

  //右方向
  r_cnt = 0;
  for (int i = y + 1; i <= 8; i++) {
    if (grid[x][i] == you) r_cnt++;
    else if (grid[x][i] == me) break;
    else {
      r_cnt = 0;
      break;
    }
  }
  if (r_cnt != 0) f = 1;

  //左上
  lu_cnt = 0;
  for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
      if (grid[i][j] == you) lu_cnt++;
      else if (grid[i][j] == me) break;
      else {
          lu_cnt = 0;
          break;
      }
  }
  if (lu_cnt != 0) f = 1;

  
  //右上
  ru_cnt = 0;
  for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
      if (grid[i][j] == you) ru_cnt++;
      else if (grid[i][j] == me) break;
      else {
          ru_cnt = 0;
          break;
      }
  }
  if (ru_cnt != 0) f = 1;


  //左下
  ld_cnt = 0;
  for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
      if (grid[i][j] == you) ld_cnt++;
      else if (grid[i][j] == me) break;
      else {
          ld_cnt = 0;
          break;
      }
  }
  if (ld_cnt != 0) f = 1;


  //右下
  rd_cnt = 0;
  for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
      if (grid[i][j] == you) rd_cnt++;
      else if (grid[i][j] == me) break;
      else {
          rd_cnt = 0;
          break;
      }
  }
  if (rd_cnt != 0) f = 1;

  return f;
}

// 入力
void PLAY () {
  if (turn) {
    me = "●";
    you = "○";
  }
  else {
    me = "○";
    you = "●";
  }

  int x = -1, y = -1;

  if (turn) cout << "Aさんのターン" <<  endl;
  else cout << "Bさんのターン" << endl;

  if (me == "●")
    cout << "あなたの色：" << "黒" << endl;
  else 
    cout << "あなたの色：" << "白" << endl;

  while ((x < 1 || x > 8) || x == -1 ) {
    cout << "縦の番号を入力：";
    cin >> x;
  }
  while ((y < 1 || y > 8) || y == -1) {
    cout << "横の番号を入力：";
    cin >> y;
  }

  cout << "ME:" << me << endl;
  cout << "YOU:" << you << endl;
  if(SEARCH(x, y)) {
     REPLACE(x, y);
    turn = !turn;
  }
  UPDATE();
}

//初期構築
int main () {
  line.assign(20, '=');
  grid[0][0] = "/";
  for (int i = 1; i < 9; i++) {
    grid[0][i] = to_string(i);
    grid[i][0] = to_string(i);
  }
  grid[4][4] = "○";
  grid[5][5] = "○";
  grid[4][5] = "●";
  grid[5][4] = "●";
  UPDATE();
  while (1) {
    PLAY();
  }
}