#include <bits/stdc++.h>
using namespace std;

int m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<vector<int>> v(50, vector<int>(50, 0));
vector<vector<bool>> visited(50, vector<bool>(50, false));

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && v[nx][ny] == 1) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

void init() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = 0;
      visited[i][j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k, cnt = 0;
    cin >> m >> n >> k;
    init();
    while (k--) {
      int x, y;
      cin >> x >> y;
      v[x][y] = 1;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] == 1 && !visited[i][j]) {
          bfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}