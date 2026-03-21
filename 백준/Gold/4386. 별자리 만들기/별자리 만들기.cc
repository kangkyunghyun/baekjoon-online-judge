#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>

int N;
vector<pdd> graph[100];

double prim() {
  priority_queue<pdd> pq;
  vector<int> visited(N, 0);
  visited[0] = 1;
  for (pdd edge : graph[0])
    pq.push(edge);
  double cost = 0;
  while (!pq.empty()) {
    double weight = -pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost += weight;
      for (pdd next : graph[node])
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
  vector<pdd> xy(N);
  for (int i = 0; i < N; i++)
    cin >> xy[i].first >> xy[i].second;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      double dist = sqrt(pow(xy[i].first - xy[j].first, 2) + pow(xy[i].second - xy[j].second, 2));
      graph[i].push_back({-dist, j});
      graph[j].push_back({-dist, i});
    }
  cout.precision(2);
  cout << fixed << prim();
  return 0;
}