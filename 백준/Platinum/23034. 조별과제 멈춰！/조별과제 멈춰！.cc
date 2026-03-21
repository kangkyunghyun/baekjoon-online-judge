#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>

int V, E, Q;
vector<piii> edges[1001];
vector<pii> mst_edges[1001];
vector<vector<int>> dist(1001, vector<int>(1001, -1));

int prim() {
  priority_queue<piii> pq;
  vector<int> visited(V + 1, 0);
  visited[1] = 1;
  for (piii edge : edges[1])
    pq.push(edge);
  int cost = 0, cnt = 1;
  while (cnt < V) {
    int weight = -pq.top().first;
    int node = pq.top().second.first;
    int curr = pq.top().second.second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost += weight;
      cnt++;
      mst_edges[curr].push_back({node, weight});
      mst_edges[node].push_back({curr, weight});
      for (piii next : edges[node])
        if (!visited[next.second.first])
          pq.push(next);
    }
  }
  return cost;
}

void bfs(int s) {
  queue<pii> q;
  dist[s][s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    auto [curr, maxWeight] = q.front();
    q.pop();
    for (auto [next, weight] : mst_edges[curr])
      if (dist[s][next] == -1) {
        int tmp = max(maxWeight, weight);
        dist[s][next] = tmp;
        q.push({next, tmp});
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> V >> E;
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({-c, {b, a}});
    edges[b].push_back({-c, {a, b}});
  }
  int mst = prim();
  for (int i = 1; i <= V; i++)
    bfs(i);
  cin >> Q;
  while (Q--) {
    int X, Y;
    cin >> X >> Y;
    cout << mst - dist[X][Y] << '\n';
  }
  return 0;
}