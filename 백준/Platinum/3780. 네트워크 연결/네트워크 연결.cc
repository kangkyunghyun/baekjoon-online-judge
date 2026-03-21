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

void merge(int x, int y) {
  dist[x] = abs(x - y) % 1000;
  p[x] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    p.resize(N + 1);
    iota(p.begin(), p.end(), 0);
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), 0);
    while (1) {
      char c;
      cin >> c;
      if (c == 'E') {
        int i;
        cin >> i;
        find(i);
        cout << dist[i] << '\n';
      } else if (c == 'I') {
        int i, j;
        cin >> i >> j;
        merge(i, j);
      } else {
        break;
      }
    }
  }
  return 0;
}