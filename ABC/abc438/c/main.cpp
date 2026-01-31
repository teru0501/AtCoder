// abc438 C - 1D puyopuyo
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  vector<int> st;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    st.push_back(tmp);
    if (st.size() >= 4){
      int l = st.size();
      if (st[l - 4] == st[l - 3] && st[l - 4] == st[l - 2] && st[l - 4] == st[l - 1]){
        for (int i = 0; i < 4; i++)
          st.pop_back();
      }
    }
  }
  cout << st.size() << endl;
}
