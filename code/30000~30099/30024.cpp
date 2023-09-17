#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m;
  int arr[1001][1001];
  priority_queue<pair<int, pair<int, int>>> pq;
  int visited[1001][1001] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        pq.push({arr[i][j], {i, j}});
        visited[i][j] = 1;
      }
    }
  }
  cin >> k;
  int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  vector<pair<int, int>> ans;
  for (int i = 0; i < k; i++) {
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    int c = pq.top().first;
    pq.pop();
    ans.push_back({x, y});
    for (int j = 0; j < 4; j++) {
      int nx = x + dx[j];
      int ny = y + dy[j];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (!visited[nx][ny]) {
        visited[nx][ny] = 1;
        pq.push({arr[nx][ny], {nx, ny}});
      }
    }
  }
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
  return 0;
}