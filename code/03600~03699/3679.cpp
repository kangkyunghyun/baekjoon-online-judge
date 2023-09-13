#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y, i;
};

ll n, t;
vector<Point> p;

ll ccw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmpY(Point a, Point b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y < b.y;
}

ll dist(Point a, Point b) {
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

bool cmpCCW(Point a, Point b) {
  ll cc = ccw(p[0], a, b);
  if (cc)
    return cc > 0;
  return dist(p[0], a) < dist(p[0], b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      p[i] = {x, y, i};
    }
    sort(p.begin(), p.end(), cmpY);
    sort(p.begin() + 1, p.end(), cmpCCW);
    int i = n - 1;
    while (!ccw(p[0], p[i], p[i - 1]))
      i--;
    reverse(p.begin() + i, p.end());
    for (auto i : p)
      cout << i.i << ' ';
    cout << '\n';
  }
  return 0;
}