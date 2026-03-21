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
    int S, P, cnt = 0;
    double ans = 0;
    cin >> S >> P;
    p.resize(P + 1);
    iota(p.begin(), p.end(), 0);
    vector<pair<double, pair<int, int>>> edge;
    vector<pair<int, int>> xy(P + 1);
    for (int i = 1; i <= P; i++)
      cin >> xy[i].first >> xy[i].second;
    for (int i = 1; i < P; i++)
      for (int j = i + 1; j <= P; j++) {
        auto [x1, y1] = xy[i];
        auto [x2, y2] = xy[j];
        double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        edge.push_back({d, {i, j}});
      }
    sort(edge.begin(), edge.end());
    for (auto [weight, path] : edge)
      if (find(path.first) != find(path.second)) {
        ans = weight;
        merge(path.first, path.second);
        if (++cnt == P - S)
          break;
      }
    cout.precision(2);
    cout << fixed << ans << '\n';
  }
  return 0;
}