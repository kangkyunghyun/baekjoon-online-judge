#include <bits/stdc++.h>
using namespace std;

int r, c, v, k;
string arr[250];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[250][250] = {0};

void bfs(int xx, int yy) {
  int vv = 0, kk = 0;
  queue<pair<int, int>> q;
  visited[xx][yy] = 1;
  q.push({xx, yy});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (arr[x][y] == 'v')
      vv++;
    else if (arr[x][y] == 'k')
      kk++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= r || ny >= c)
        continue;
      if (!visited[nx][ny] && arr[nx][ny] != '#') {
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  if (kk > vv)
    v -= vv;
  else
    k -= kk;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  vector<pair<int, int>> xy;
  for (int i = 0; i < r; i++) {
    cin >> arr[i];
    for (int j = 0; j < c; j++) {
      if (arr[i][j] == 'v') {
        v++;
        xy.push_back({i, j});
      } else if (arr[i][j] == 'k') {
        k++;
        xy.push_back({i, j});
      }
    }
  }
  for (auto [x, y] : xy)
    if (!visited[x][y])
      bfs(x, y);
  cout << k << ' ' << v;
  return 0;
}