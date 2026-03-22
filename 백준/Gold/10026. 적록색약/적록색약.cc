#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<string> graph(101, "");
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
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < n && graph[nx][ny] == graph[x][y] && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> graph[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (!visited[i][j]) {
        bfs(i, j);
        cnt++;
      }
  }
  cout << cnt << ' ';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 'R')
        graph[i][j] = 'G';
      visited[i][j] = 0;
    }
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (!visited[i][j]) {
        bfs(i, j);
        cnt++;
      }
  }
  cout << cnt;
  return 0;
}