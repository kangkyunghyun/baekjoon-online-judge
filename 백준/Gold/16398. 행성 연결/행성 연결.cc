#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N;
vector<pii> graph[10001];

long long prim() {
  priority_queue<pii> pq;
  vector<int> visited(N + 1, 0);
  visited[1] = 1;
  for (pii edge : graph[1])
    pq.push(edge);
  long long cost = 0;
  while (!pq.empty()) {
    auto [weight, node] = pq.top();
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost -= weight;
      for (pii next : graph[node])
        if (!visited[next.second])
          pq.push(next);
    }
  }
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int w;
      cin >> w;
      graph[i].push_back({-w, j});
      graph[j].push_back({-w, i});
    }
  cout << prim();
  return 0;
}