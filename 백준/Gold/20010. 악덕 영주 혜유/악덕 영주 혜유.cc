#include <bits/stdc++.h>
using namespace std;

int N, K, mst_weight = 0, M = 0, X;
vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> mst[10001];
vector<int> p, visited(10001, 0);

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    p[y] = x;
  else
    p[x] = y;
}

void dfs(int curr, int sum) {
  if (mst[curr].size() == 1 && sum) {
    if (sum > M) {
      M = sum;
      X = curr;
    }
    return;
  }
  for (auto [next, weight] : mst[curr])
    if (!visited[next]) {
      visited[next] = 1;
      dfs(next, sum + weight);
      visited[next] = 0;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  p.resize(N);
  iota(p.begin(), p.end(), 0);
  while (K--) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, {a, b}});
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      mst_weight += weight;
      mst[path.first].push_back({path.second, weight});
      mst[path.second].push_back({path.first, weight});
      merge(path.first, path.second);
    }
  cout << mst_weight << '\n';
  visited[1] = 1;
  dfs(1, 0);
  visited[1] = 0;
  M = 0;
  visited[X] = 1;
  dfs(X, 0);
  cout << M;
  return 0;
}