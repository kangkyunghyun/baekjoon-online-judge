// 17386: 선분 교차 1
//
// - 문제
// 2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.
// L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.
//
// - 입력
// 첫째 줄에 L1의 양 끝 점 x1, y1, x2, y2가, 둘째 줄에 L2의 양 끝 점 x3, y3, x4, y4가 주어진다. 세 점이 일직선 위에 있는 경우는 없다.
//
// - 출력
// L1과 L2가 교차하면 1, 아니면 0을 출력한다.
//
// - 제한
// -1,000,000 ≤ x1, y1, x2, y2, x3, y3, x4, y4 ≤ 1,000,000
// x1, y1, x2, y2, x3, y3, x4, y4는 정수
// 선분의 길이는 0보다 크다.

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