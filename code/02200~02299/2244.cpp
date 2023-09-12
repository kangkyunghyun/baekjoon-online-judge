#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y;
};

ll n, m;
vector<Point> p, p1, p2, s;

ll ccw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmpX(Point a, Point b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

bool cmpCCW(Point a, Point b) {
  ll cc = ccw(p[0], a, b);
  return cc ? cc > 0 : cmpX(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  p1.resize(n);
  p2.resize(m);
  for (int i = 0; i < n; i++)
    cin >> p1[i].x >> p1[i].y;
  for (int i = 0; i < m; i++)
    cin >> p2[i].x >> p2[i].y;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      p.push_back({p1[i].x + p2[j].x, p1[i].y + p2[j].y});
  sort(p.begin(), p.end(), cmpX);
  sort(p.begin() + 1, p.end(), cmpCCW);
  s.push_back(p[0]);
  s.push_back(p[1]);
  for (int i = 2; i < n * m; i++) {
    while (s.size() >= 2) {
      Point second = s.back();
      s.pop_back();
      Point first = s.back();
      if (ccw(first, second, p[i]) > 0) {
        s.push_back(second);
        break;
      }
    }
    s.push_back(p[i]);
  }
  cout << s.size() << '\n';
  for (Point i : s)
    cout << i.x << ' ' << i.y << '\n';
  return 0;
}