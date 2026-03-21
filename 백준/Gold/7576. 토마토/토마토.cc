#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> graph(1001, vector<int>(1001));
vector<vector<int>> visited(1001, vector<int>(1001, 0));
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= 0 && nx >= 0 && ny < n && nx < m && graph[ny][nx] == 0) {
        q.push({ny, nx});
        graph[ny][nx] = 1;
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> graph[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (graph[i][j] == 1)
        q.push({i, j});

  bfs();

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (graph[i][j] == 0) {
        cout << -1;
        return 0;
      }
      if (visited[i][j] > ans)
        ans = visited[i][j];
    }
  cout << ans;
  return 0;
}