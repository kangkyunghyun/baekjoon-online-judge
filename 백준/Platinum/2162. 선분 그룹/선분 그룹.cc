#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n;
vector<pair<pii, pii>> lines;
vector<int> p, cnt;

ll ccw(pii a, pii b, pii c) {
  ll cc = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
  if (cc > 0)
    return 1;
  else if (cc < 0)
    return -1;
  return 0;
}

bool check(pii a, pii b, pii c, pii d) {
  ll cc1 = ccw(a, b, c) * ccw(a, b, d);
  ll cc2 = ccw(c, d, a) * ccw(c, d, b);
  if (cc1 == 0 && cc2 == 0) {
    if (a > b)
      swap(a, b);
    if (c > d)
      swap(c, d);
    return a <= d && c <= b;
  }
  return cc1 <= 0 && cc2 <= 0;
}

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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  lines.resize(n);
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines[i] = {{x1, y1}, {x2, y2}};
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (check(lines[i].first, lines[i].second, lines[j].first, lines[j].second))
        merge(i, j);
  for (int i = 0; i < n; i++)
    find(i);
  cnt.resize(n, 0);
  for (int i = 0; i < n; i++)
    cnt[p[i]]++;
  int ans1 = 0, ans2 = 0;
  for (int i : cnt)
    if (i) {
      ans1++;
      ans2 = max(ans2, i);
    }
  cout << ans1 << '\n'
       << ans2;
  return 0;
}