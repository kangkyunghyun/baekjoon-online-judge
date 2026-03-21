#include <bits/stdc++.h>
using namespace std;

int n, m, t = 0, graph[100][100], visited[100][100];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  visited[xx][yy] = 1;
  q.push({xx, yy});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (!visited[nx][ny] && graph[nx][ny] == 0) {
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      visited[i][j] = 0;
    }
  bfs(0, 0);
  while (1) {
    t++;
    vector<pair<int, int>> hole;
    bool flag = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (graph[i][j] == 1)
          if (!visited[i][j]) {
            int cnt = 0;
            for (int a = 0; a < 4; a++) {
              int x = i + dx[a];
              int y = j + dy[a];
              if (visited[x][y])
                cnt++;
            }
            if (cnt >= 2)
              hole.push_back({i, j});
            else
              flag = false;
          }
    for (auto p : hole) {
      int x = p.first;
      int y = p.second;
      bfs(x, y);
    }
    if (flag)
      break;
  }
  cout << t;
  return 0;
}