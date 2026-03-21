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

void check(int x, int y) {
  x = find(x);
  y = find(y);
  cout << (x == y ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  p.resize(n + 1);
  iota(p.begin(), p.end(), 0);
  while (m--) {
    int c, a, b;
    cin >> c >> a >> b;
    if (c)
      check(a, b);
    else
      merge(a, b);
  }
  return 0;
}