#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<vector<int>> graph(1001, vector<int>(1001, 0));
vector<bool> visited(1001, false);

void dfs(int start) {
  visited[start] = true;
  cout << start << ' ';
  for (int i = 1; i <= n; i++) {
    if (graph[start][i] == 1 && !visited[i])
      dfs(i);
  }
}

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  cout << start << ' ';
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (graph[x][i] == 1 && !visited[i]) {
        q.push(i);
        visited[i] = true;
        cout << i << ' ';
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m >> v;
  while (m--) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  dfs(v);
  cout << '\n';
  for (int i = 1; i <= n; i++)
    visited[i] = 0;
  bfs(v);
  return 0;
}