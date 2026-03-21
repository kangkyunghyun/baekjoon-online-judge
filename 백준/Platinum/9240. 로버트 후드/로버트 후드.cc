#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y;
};

int n;
double ans = 0;
vector<Point> p, s;

ll ccw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmpY(Point a, Point b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y < b.y;
}

bool cmpCCW(Point a, Point b) {
  ll cc = ccw(p[0], a, b);
  return cc ? cc > 0 : cmpY(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;
  sort(p.begin(), p.end(), cmpY);
  sort(p.begin() + 1, p.end(), cmpCCW);
  s.push_back(p[0]);
  s.push_back(p[1]);
  for (int i = 2; i < n; i++) {
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
  for (int i = 0; i < s.size() - 1; i++)
    for (int j = i + 1; j < s.size(); j++)
      ans = max(ans, sqrt(pow(s[i].x - s[j].x, 2) + pow(s[i].y - s[j].y, 2)));
  cout.precision(9);
  cout << fixed << ans;
  return 0;
}