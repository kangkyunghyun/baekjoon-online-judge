#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N, C = 0, M = 0;
vector<pair<int, pii>> edge;
vector<pii> mst;
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
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int x;
      cin >> x;
      if (x < 0) {
        merge(i, j);
        C -= x;
      } else {
        edge.push_back({x, {i, j}});
      }
    }
  C /= 2;
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      C += weight;
      mst.push_back(path);
      merge(path.first, path.second);
    }
  cout << C << ' ' << mst.size() << '\n';
  for (auto [x, y] : mst)
    cout << x << ' ' << y << '\n';
  return 0;
}