#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, ans = 0;
int graph[101][101], visited[101][101] = {0};
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
      continue;
    if (!visited[nx][ny] && graph[nx][ny] == 0) {
      if (cnt == k) {
        ans++;
        visited[nx][ny] = 1;
        cnt = 1;
        dfs(nx, ny);
      } else {
        visited[nx][ny] = ++cnt;
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> graph[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!visited[i][j] && graph[i][j] == 0) {
        cnt = 1;
        ans++;
        visited[i][j] = 1;
        dfs(i, j);
      }
  if (ans > m) {
    cout << "IMPOSSIBLE";
  } else if (ans == 0) {
    cout << "IMPOSSIBLE";
  } else {
    cout << "POSSIBLE\n"
         << m - ans;
  }
  return 0;
}