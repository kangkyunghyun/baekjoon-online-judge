#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<pair<int, pair<int, int>>> edge;

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

int kruskal() {
  iota(p.begin(), p.end(), 0);
  int cnt = 0;
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      cnt += weight;
      merge(path.first, path.second);
    }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n + m + k == 0)
      break;
    p.resize(n + 1);
    edge.clear();
    while (m--) {
      char c;
      int f, t;
      cin >> c >> f >> t;
      if (c == 'B')
        edge.push_back({1, {f, t}});
      else
        edge.push_back({0, {f, t}});
    }
    sort(edge.begin(), edge.end());
    int minBlue = kruskal();
    sort(edge.begin(), edge.end(), greater<>());
    int maxBlue = kruskal();
    if (minBlue <= k && k <= maxBlue)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}