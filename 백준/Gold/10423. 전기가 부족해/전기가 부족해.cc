#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int V, E, K;
vector<pii> graph[100001];
priority_queue<pii> pq;
vector<int> visited(100001, 0);

int prim() {
  int cost = 0;
  while (!pq.empty()) {
    int weight = -pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost += weight;
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
  cin >> V >> E >> K;
  vector<int> p(K);
  for (int i = 0; i < K; i++)
    cin >> p[i];
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({-c, b});
    graph[b].push_back({-c, a});
  }
  for (int i : p) {
    visited[i] = 1;
    for (pii edge : graph[i])
      pq.push(edge);
  }
  cout << prim();
  return 0;
}