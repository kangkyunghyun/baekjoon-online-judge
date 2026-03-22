#include <bits/stdc++.h>
using namespace std;

int N, A, B, M = 0;
vector<pair<int, int>> graph[100001];
vector<int> visited(100001, 0);

void dfs(int curr, int dist, int d) {
  if (curr == B) {
    cout << dist - d << '\n';
    return;
  }
  visited[curr] = 1;
  for (auto i : graph[curr]) {
    int next = i.first;
    int cost = i.second;
    if (!visited[next])
      dfs(next, dist + cost, max(d, cost));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> A >> B;
  for (int i = 1; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  visited[0] = 0;
  dfs(A, 0, 0);
  return 0;
}