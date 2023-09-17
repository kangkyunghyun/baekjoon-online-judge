#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int I, n, k;
  string ink;
  cin >> I >> n >> k >> ink;
  string arr[100];
  int x, y;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '@') {
        x = i;
        y = j;
      } else if (arr[i][j] == '#')
        v.push_back({i, j});
    }
  }
  string s;
  cin >> s;
  int cnt = 0, m = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == 'D') {
      if (x + 1 < n && arr[x + 1][y] == '.') {
        arr[x][y] = '.';
        x++;
        arr[x][y] = '@';
      }
    } else if (s[i] == 'U') {
      if (x - 1 >= 0 && arr[x - 1][y] == '.') {
        arr[x][y] = '.';
        x--;
        arr[x][y] = '@';
      }
    } else if (s[i] == 'L') {
      if (y - 1 >= 0 && arr[x][y - 1] == '.') {
        arr[x][y] = '.';
        y--;
        arr[x][y] = '@';
      }
    } else if (s[i] == 'R') {
      if (y + 1 < n && arr[x][y + 1] == '.') {
        arr[x][y] = '.';
        y++;
        arr[x][y] = '@';
      }
    } else if (s[i] == 'j') {
      m++;
    } else {
      if (m) {
        for (int j = 0; j < v.size(); j++) {
          if (abs(v[j].first - x) + abs(v[j].second - y) <= m)
            arr[v[j].first][v[j].second] = ink[cnt];
        }
        m = 0;
      }
      cnt = (cnt + 1) % I;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << arr[i][j];
    cout << '\n';
  }
}