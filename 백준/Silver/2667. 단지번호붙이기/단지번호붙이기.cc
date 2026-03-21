#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
vector<string> graph(26);
vector<vector<int>> visited(26, vector<int>(26, 0));
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    visited[x][y] = cnt;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx > 0 && ny > 0 && nx <= n && ny <= n && (graph[nx][ny - 1] - '0') && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = cnt;
      }
    }
  }
  cnt++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> graph[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if ((graph[i][j - 1] - '0') && !visited[i][j])
        bfs(i, j);
  vector<int> ans;
  for (int i = 1; i < cnt; i++) {
    int tmp = 0;
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (visited[j][k] == i)
          tmp++;
    ans.push_back(tmp);
  }
  sort(ans.begin(), ans.end());
  cout << cnt - 1 << '\n';
  for (int i : ans)
    cout << i << '\n';
  return 0;
}