#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> p(300001), visited(300001, 0);

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  p[x] = y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L;
  iota(p.begin(), p.end(), 0);
  while (N--) {
    int a, b;
    cin >> a >> b;
    if (!visited[a]) {
      cout << "LADICA\n";
      visited[a] = 1;
      merge(a, b);
    } else if (!visited[b]) {
      cout << "LADICA\n";
      visited[b] = 1;
      merge(b, a);
    } else if (!visited[find(a)]) {
      cout << "LADICA\n";
      visited[find(a)] = 1;
      merge(a, b);
    } else if (!visited[find(b)]) {
      cout << "LADICA\n";
      visited[find(b)] = 1;
      merge(b, a);
    } else {
      cout << "SMECE\n";
    }
  }
  return 0;
}