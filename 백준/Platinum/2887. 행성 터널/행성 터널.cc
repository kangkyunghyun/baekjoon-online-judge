#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N;
vector<pii> graph[100001];

int prim() {
  priority_queue<pii> pq;
  vector<int> visited(N + 1, 0);
  visited[1] = 1;
  for (pii edge : graph[1])
    pq.push(edge);
  int cost = 0, cnt = 1;
  while (cnt < N) {
    auto [weight, node] = pq.top();
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost -= weight;
      cnt++;
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
  vector<pair<int, int>> x, y, z;
  for (int i = 1; i <= N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    x.push_back({a, i});
    y.push_back({b, i});
    z.push_back({c, i});
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());
  for (int i = 0; i < N - 1; i++) {
    graph[x[i].second].push_back({-abs(x[i].first - x[i + 1].first), x[i + 1].second});
    graph[x[i + 1].second].push_back({-abs(x[i].first - x[i + 1].first), x[i].second});
    graph[y[i].second].push_back({-abs(y[i].first - y[i + 1].first), y[i + 1].second});
    graph[y[i + 1].second].push_back({-abs(y[i].first - y[i + 1].first), y[i].second});
    graph[z[i].second].push_back({-abs(z[i].first - z[i + 1].first), z[i + 1].second});
    graph[z[i + 1].second].push_back({-abs(z[i].first - z[i + 1].first), z[i].second});
  }
  cout << prim();
  return 0;
}