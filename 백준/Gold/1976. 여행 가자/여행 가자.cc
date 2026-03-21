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
  int n, m;
  cin >> n >> m;
  p.resize(n + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (x)
        merge(i, j);
    }
  vector<int> v(m);
  for (int i = 0; i < m; i++)
    cin >> v[i];
  int x = find(v[0]);
  string ans = "YES";
  for (int i = 1; i < m; i++)
    if (x != find(v[i]))
      ans = "NO";
  cout << ans;
  return 0;
}