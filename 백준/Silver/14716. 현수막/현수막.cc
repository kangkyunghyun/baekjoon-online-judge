#include <bits/stdc++.h>
using namespace std;

int n, m, a[250][250], visited[250][250], cnt = 0;

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});
  visited[xx][yy] = ++cnt;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (a[nx][ny] && !visited[nx][ny]) {
          q.push({nx, ny});
          visited[nx][ny] = cnt;
        }
      }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] && !visited[i][j])
        bfs(i, j);
  cout << cnt;
  return 0;
}