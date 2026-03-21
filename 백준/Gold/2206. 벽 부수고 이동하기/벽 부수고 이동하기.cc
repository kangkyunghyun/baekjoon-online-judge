#include <bits/stdc++.h>
using namespace std;

int n, m;
string graph[1001];
int visited[1001][1001][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int cc, int xx, int yy) {
  queue<pair<int, pair<int, int>>> q;
  q.push({cc, {xx, yy}});
  visited[xx][yy][cc] = 1;
  while (!q.empty()) {
    int c = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();
    if (x == n - 1 && y == m - 1)
      return visited[n - 1][m - 1][c];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (graph[nx][ny] == '1' && c == 1) {
        visited[nx][ny][c - 1] = visited[x][y][c] + 1;
        q.push({c - 1, {nx, ny}});
      } else if (graph[nx][ny] == '0' && visited[nx][ny][c] == 0) {
        visited[nx][ny][c] = visited[x][y][c] + 1;
        q.push({c, {nx, ny}});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> graph[i];
  cout << bfs(1, 0, 0) << '\n';
  return 0;
}