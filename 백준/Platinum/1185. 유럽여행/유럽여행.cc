#include <bits/stdc++.h>
using namespace std;

int N, P, cost = 0;
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
  cin >> N >> P;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  vector<int> c(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> c[i];
  while (P--) {
    int S, E, L;
    cin >> S >> E >> L;
    edge.push_back({2 * L + c[S] + c[E], {S, E}});
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      cost += weight;
      merge(path.first, path.second);
    }
  cout << cost + *min_element(c.begin() + 1, c.end());
  return 0;
}