#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

vector<pair<pll, pll>> lines;

ll ccw(pll a, pll b, pll c) {
  ll cc = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
  if (cc > 0)
    return 1;
  else if (cc < 0)
    return -1;
  return 0;
}

bool check(pll a, pll b, pll c, pll d) {
  ll cc1 = ccw(a, b, c) * ccw(a, b, d);
  ll cc2 = ccw(c, d, a) * ccw(c, d, b);
  return cc1 < 0 && cc2 < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  lines.resize(2);
  for (int i = 0; i < 2; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines[i] = {{x1, y1}, {x2, y2}};
  }
  cout << check(lines[0].first, lines[0].second, lines[1].first, lines[1].second);
  return 0;
}