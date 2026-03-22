#include <bits/stdc++.h>
using namespace std;

int m, n, h;
vector<vector<vector<int>>> graph(101, vector<vector<int>>(101, vector<int>(101)));
vector<vector<vector<int>>> visited(101, vector<vector<int>>(101, vector<int>(101, 0)));
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<pair<int, pair<int, int>>> q;

void bfs() {
  while (!q.empty()) {
    int z = q.front().first;
    int y = q.front().second.first;
    int x = q.front().second.second;
    q.pop();

    for (int i = 0; i < 6; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int nz = z + dz[i];

      if (ny >= 0 && nx >= 0 && nz >= 0 && ny < n && nx < m && nz < h && graph[nz][ny][nx] == 0) {
        q.push({nz, {ny, nx}});
        graph[nz][ny][nx] = 1;
        visited[nz][ny][nx] = visited[z][y][x] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> m >> n >> h;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> graph[k][i][j];

  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (graph[k][i][j] == 1)
          q.push({k, {i, j}});

  bfs();

  int ans = 0;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (graph[k][i][j] == 0) {
          cout << -1;
          return 0;
        }
        if (visited[k][i][j] > ans)
          ans = visited[k][i][j];
      }
  cout << ans;
  return 0;
}