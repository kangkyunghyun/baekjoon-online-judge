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
    p[x] = y;
  else
    p[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, K;
  cin >> N >> M >> K;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  vector<int> c(M);
  for (int i = 0; i < M; i++)
    cin >> c[i];
  sort(c.begin(), c.end());
  while (K--) {
    int x;
    cin >> x;
    int idx = find(upper_bound(c.begin(), c.end(), x) - c.begin());
    cout << c[idx] << '\n';
    merge(idx, idx + 1);
  }
  return 0;
}