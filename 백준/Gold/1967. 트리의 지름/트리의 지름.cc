#include <bits/stdc++.h>
using namespace std;

int N, M = 0, X;
vector<pair<int, int>> edge[10001];
vector<int> visited(10001, 0);

void dfs(int curr, int sum) {
  if (edge[curr].size() == 1 && sum) {
    if (sum > M) {
      M = sum;
      X = curr;
    }
    return;
  }
  for (auto [next, weight] : edge[curr])
    if (!visited[next]) {
      visited[next] = 1;
      dfs(next, sum + weight);
      visited[next] = 0;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while (--N) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].push_back({v, w});
    edge[v].push_back({u, w});
  }
  visited[1] = 1;
  dfs(1, 0);
  visited[1] = 0;
  M = 0;
  visited[X] = 1;
  dfs(X, 0);
  cout << M;
  return 0;
}