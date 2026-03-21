#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(1001, vector<int>(1001));
vector<int> visited(1001, 0);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= n; i++)
      if (graph[x][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!visited[i]) {
      bfs(i);
      ans++;
    }
  cout << ans;
  return 0;
}