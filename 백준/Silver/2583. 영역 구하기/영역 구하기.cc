#include <bits/stdc++.h>
using namespace std;

int m, n, k, cnt = 0;
int visited[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});
  visited[xx][yy] = ++cnt;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (!visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = cnt;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
      for (int j = y1; j < y2; j++)
        visited[i][j] = -1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!visited[i][j])
        bfs(i, j);
  vector<int> ans(cnt + 1, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (visited[i][j] != -1)
        ans[visited[i][j]]++;
  sort(ans.begin(), ans.end());
  cout << cnt << '\n';
  for (int i = 1; i <= cnt; i++)
    cout << ans[i] << ' ';
  return 0;
}