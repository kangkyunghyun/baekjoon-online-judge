#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

void find(pll a, pll b, pll c, pll d) {
  double p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
  double px = (a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
  double py = (a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x);
  if (p == 0) {
    if (a == d && c <= a)
      cout << a.x << ' ' << a.y;
    else if (b == c && a <= c)
      cout << b.x << ' ' << b.y;
  } else {
    double x = px / p;
    double y = py / p;
    cout.precision(9);
    cout << fixed << x << ' ' << y;
  }
}

ll ccw(pll a, pll b, pll c) {
  ll cc = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
  if (cc > 0)
    return 1;
  else if (cc < 0)
    return -1;
  return 0;
}

void check(pll a, pll b, pll c, pll d) {
  ll cc1 = ccw(a, b, c) * ccw(a, b, d);
  ll cc2 = ccw(c, d, a) * ccw(c, d, b);
  if (cc1 == 0 && cc2 == 0) {
    if (a > b)
      swap(a, b);
    if (c > d)
      swap(c, d);
    if (a <= d && c <= b) {
      cout << 1 << '\n';
      find(a, b, c, d);
    } else {
      cout << 0 << '\n';
    }
  } else {
    if (cc1 <= 0 && cc2 <= 0) {
      cout << 1 << '\n';
      find(a, b, c, d);
    } else {
      cout << 0 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pll> p(4);
  for (int i = 0; i < 4; i++)
    cin >> p[i].x >> p[i].y;
  check(p[0], p[1], p[2], p[3]);
  return 0;
}