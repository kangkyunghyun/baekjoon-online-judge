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
  cin >> N >> M;
  p.resize(N);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      cout << i;
      return 0;
    }
    merge(x, y);
  }
  cout << 0;
  return 0;
}