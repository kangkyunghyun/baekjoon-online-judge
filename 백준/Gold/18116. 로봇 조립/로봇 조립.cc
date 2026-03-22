#include <bits/stdc++.h>
using namespace std;

vector<int> p(1000001), cnt(1000001, 1);

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (x > y)
    swap(x, y);
  cnt[x] += cnt[y];
  cnt[y] = 0;
  p[y] = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  iota(p.begin(), p.end(), 0);
  while (n--) {
    char c;
    int a, b;
    cin >> c;
    if (c == 'I') {
      cin >> a >> b;
      merge(a, b);
    } else {
      cin >> a;
      cout << cnt[find(a)] << '\n';
    }
  }
  return 0;
}