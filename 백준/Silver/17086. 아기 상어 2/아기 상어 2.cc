#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], ans = 0;
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

void bfs(int xx, int yy) {
  int cnt = 0;
  queue<pair<pair<int, int>, int>> q;
  vector<vector<int>> visited(50, vector<int>(50, -1));
  q.push({{xx, yy}, cnt});
  visited[xx][yy] = cnt;
  while (!q.empty()) {
    auto [x, y] = q.front().first;
    cnt = q.front().second + 1;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (visited[nx][ny] == -1) {
        visited[nx][ny] = cnt;
        q.push({{nx, ny}, cnt});
        if (a[nx][ny]) {
          ans = max(ans, cnt);
          return;
        }
      }
    }
  }
  ans = cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> v;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (!a[i][j])
        v.push_back({i, j});
    }
  for (int i = 0; i < v.size(); i++)
    bfs(v[i].first, v[i].second);
  cout << ans;
  return 0;
}