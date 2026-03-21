#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int V, E, P;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF), visited(20001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= V; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
}

int dijkstra(int s, int e) {
  init();
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]);
    if (visited[curr])
      break;
    visited[curr] = 1;
    for (auto &p : graph[curr]) {
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
  return dist[e];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> V >> E >> P;
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  if (dijkstra(1, P) + dijkstra(P, V) == dijkstra(1, V))
    cout << "SAVE HIM\n";
  else
    cout << "GOOD BYE\n";
  return 0;
}