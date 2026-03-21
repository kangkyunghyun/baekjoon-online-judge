#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(101, vector<int>(101, 0));
vector<int> visited(101, 0);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    visited[x] = 1;
    for (int i = 1; i <= n; i++)
      if (graph[x][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
        ans++;
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
  bfs(1);
  cout << ans;
  return 0;
}