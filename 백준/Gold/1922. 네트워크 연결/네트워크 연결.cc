#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

int N, M, visited[1001] = {0}, ans = 0;
vector<p> graph[1001];

struct cmp {
  bool operator()(p a, p b) {
    return a.second > b.second;
  }
};

void prim_mst() {
  priority_queue<p, vector<p>, cmp> pq;
  for (int i = 0; i < graph[1].size(); i++)
    pq.push(graph[1][i]);
  visited[1] = 1;
  int cnt = 0;
  while (cnt < N - 1) {
    int node = pq.top().first;
    int cost = pq.top().second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cnt++;
      ans += cost;
      for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].first;
        if (!visited[next])
          pq.push(graph[node][i]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  prim_mst();
  cout << ans;
  return 0;
}