#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y;
};

int n;
vector<Point> p, s;

ll ccw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmpX(Point a, Point b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

bool cmpY(Point a, Point b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y > b.y;
}

bool cmpCCW(Point a, Point b) {
  ll cc = ccw(p[0], a, b);
  return cc ? cc > 0 : cmpY(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if (c == 'Y')
      p.push_back({x, y});
  }
  sort(p.begin(), p.end(), cmpX);
  sort(p.begin() + 1, p.end(), cmpCCW);
  s.push_back(p[0]);
  s.push_back(p[1]);
  for (int i = 2; i < p.size(); i++) {
    while (s.size() >= 2) {
      Point second = s.back();
      s.pop_back();
      Point first = s.back();
      if (ccw(first, second, p[i]) >= 0) {
        s.push_back(second);
        break;
      }
    }
    s.push_back(p[i]);
  }
  cout << s.size() << '\n';
  for (auto [x, y] : s)
    cout << x << ' ' << y << '\n';
  return 0;
}