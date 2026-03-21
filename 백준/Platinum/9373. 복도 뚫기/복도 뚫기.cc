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
  int T;
  cin >> T;
  while (T--) {
    int w, n;
    vector<pair<double, pair<int, int>>> edge;
    vector<tuple<int, int, int>> pos;
    cin >> w >> n;
    edge.push_back({w, {n, n + 1}});
    p.resize(n + 2);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++) {
      int x, y, r;
      cin >> x >> y >> r;
      pos.push_back({r, x, y});
      if (x - r > 0)
        edge.push_back({x - r, {i, n}});
      else
        merge(i, n);
      if (w - x - r > 0)
        edge.push_back({w - x - r, {i, n + 1}});
      else
        merge(i, n + 1);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        auto [r1, x1, y1] = pos[i];
        auto [r2, x2, y2] = pos[j];
        double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) - r1 - r2;
        if (d > 0)
          edge.push_back({d, {i, j}});
        else
          merge(i, j);
      }
    sort(edge.begin(), edge.end());
    double ans = 0;
    for (auto [weight, path] : edge)
      if (find(path.first) != find(path.second)) {
        merge(path.first, path.second);
        if (find(n) == find(n + 1)) {
          ans = weight / 2;
          break;
        }
      }
    cout.precision(9);
    cout << fixed << ans << '\n';
  }
  return 0;
}