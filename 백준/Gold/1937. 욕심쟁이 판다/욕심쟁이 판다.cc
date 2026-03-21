#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
int graph[500][500] = {0}, visited[500][500] = {0};
int dx[] = {1, -1, 0, -0}, dy[] = {0, 0, 1, -1};

int dfs(int x, int y) {
  if (visited[x][y])
    return visited[x][y];
  visited[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
      continue;
    if (graph[nx][ny] > graph[x][y])
      visited[x][y] = max(visited[x][y], dfs(nx, ny) + 1);
  }
  return visited[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> graph[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans = max(ans, dfs(i, j));
  cout << ans << '\n';
  return 0;
}