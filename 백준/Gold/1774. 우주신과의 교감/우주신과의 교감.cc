#include <bits/stdc++.h>
using namespace std;

vector<int> p;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  vector<pair<double, pair<int, int>>> edge;
  cin >> N >> M;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  vector<pair<int, int>> pos(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> pos[i].first >> pos[i].second;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) {
      auto [x1, y1] = pos[i];
      auto [x2, y2] = pos[j];
      double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
      edge.push_back({d, {i, j}});
    }
  while (M--) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }
  double ans = 0;
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      ans += weight;
      merge(path.first, path.second);
    }
  cout.precision(2);
  cout << fixed << ans;
  return 0;
}