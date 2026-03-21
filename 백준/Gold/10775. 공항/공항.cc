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
  int G, P, ans = 0;
  cin >> G >> P;
  p.resize(G + 1);
  iota(p.begin(), p.end(), 0);
  while (P--) {
    int g;
    cin >> g;
    int x = find(g);
    if (x == 0) {
      break;
    } else {
      ans++;
      merge(x, x - 1);
    }
  }
  cout << ans;
  return 0;
}