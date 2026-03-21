#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
vector<pair<int, pair<int, int>>> edge;
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
  cin >> N;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    edge.push_back({x, {0, i}});
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int x;
      cin >> x;
      edge.push_back({x, {i, j}});
    }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      ans += weight;
      merge(path.first, path.second);
    }
  cout << ans;
  return 0;
}