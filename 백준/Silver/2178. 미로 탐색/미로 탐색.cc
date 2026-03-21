#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph(101, vector<int>(101));
vector<vector<int>> visited(101, vector<int>(101, 0));
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});
  visited[xx][yy] = 1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (visited[n - 1][m - 1])
      return;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ny >= 0 && nx >= 0 && ny < m && nx < n && graph[nx][ny] == 1 && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      graph[i][j] = s[j] - '0';
  }
  bfs(0, 0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (ans < visited[i][j])
        ans = visited[i][j];
  cout << ans;
  return 0;
}