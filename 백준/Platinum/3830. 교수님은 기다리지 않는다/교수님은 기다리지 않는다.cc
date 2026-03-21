#include <bits/stdc++.h>
using namespace std;

vector<int> p, dist;

int find(int x) {
  if (p[x] != x) {
    int node = find(p[x]);
    dist[x] += dist[p[x]];
    p[x] = node;
  }
  return p[x];
}

void merge(int x, int y, int w) {
  int a = find(x);
  int b = find(y);
  if (a == b)
    return;
  dist[b] = dist[x] - dist[y] + w;
  p[b] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    int N, M;
    cin >> N >> M;
    if (N + M == 0)
      break;
    p.resize(N + 1);
    iota(p.begin(), p.end(), 0);
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), 0);
    while (M--) {
      char c;
      cin >> c;
      int a, b, w;
      if (c == '?') {
        cin >> a >> b;
        if (find(a) != find(b))
          cout << "UNKNOWN\n";
        else
          cout << dist[b] - dist[a] << '\n';
      } else {
        cin >> a >> b >> w;
        merge(a, b, w);
      }
    }
  }
  return 0;
}