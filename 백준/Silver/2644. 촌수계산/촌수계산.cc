#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph(101, vector<int>(101, 0));
vector<int> visited(101, 0);

bool bfs(int a, int b) {
  queue<int> q;
  q.push(a);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= n; i++)
      if (graph[x][i] == 1 && !visited[i]) {
        q.push(i);
        visited[i] = visited[x] + 1;
        if (i == b)
          return true;
      }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  int a, b, m;
  cin >> a >> b >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  bool flag = bfs(a, b);
  int max = *max_element(visited.begin(), visited.end());
  if (flag)
    cout << max;
  else
    cout << -1;
  return 0;
}