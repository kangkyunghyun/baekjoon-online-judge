#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

int V, E, visited[10001] = {0}, ans = 0;
vector<p> graph[10001];

void mst() {
  priority_queue<p> pq;
  for (int i = 0; i < graph[1].size(); i++)
    pq.push(graph[1][i]);
  visited[1] = 1;
  int cnt = 0;
  while (cnt < V - 1) {
    int cost = -pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = ++cnt;
      ans += cost;
      for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].second;
        if (!visited[next])
          pq.push(graph[node][i]);
      }
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
    graph[a].push_back({-c, b});
    graph[b].push_back({-c, a});
  }
  mst();
  cout << ans;
  return 0;
}