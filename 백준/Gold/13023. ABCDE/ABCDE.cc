#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(2000, vector<int>(0));
vector<int> visited(2000, 0);

void dfs(int x, int cnt) {
  if (cnt == 4) {
    ans = 1;
    return;
  }
  visited[x] = 1;
  for (int i = 0; i < graph[x].size(); i++) {
    int next = graph[x][i];
    if (!visited[next])
      dfs(next, cnt + 1);
  }
  visited[x] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    if (ans)
      break;
    dfs(i, 0);
  }
  cout << ans;
  return 0;
}