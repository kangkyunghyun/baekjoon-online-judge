// 9240: 로버트 후드
//
// - 문제
// 로버트 후드는 로빈 후드의 동생이다. 로버트 후드는 자신의 형처럼 전설적인 인물이 되기 위해 활 쏘기를 연습하고 있다.
// 이번에 노팅엄에서 열린 활 쏘기 대회는 현대에 열리는 양궁과 규칙이 다르다. 양궁은 더 많은 점수를 쏜 사람이 승리하는 방식이다. 하지만, 노팅엄 활 쏘기 대회에서는 과녁에 맞은 화살 사이의 거리 중 최댓값이 가장 큰 사람이 승리한다.
// 로버트 후드는 총 C발을 발사했고, 모든 화살은 과녁에 적중했다. 과녁을 이차원 평면으로, 화살은 점으로 나타낸다. 화살의 좌표가 주어졌을 때, 가장 먼 화살의 거리를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 로버트 후드가 발사한 화살의 수 C (2 ≤ C ≤ 100,000)가 주어진다. 다음 C개 줄에는 화살의 좌표가 주어진다. 좌표는 정수이고, 절댓값은 1,000을 넘지 않는다.
//
// - 출력
// 가장 먼 두 화살의 거리를 출력한다. 상대/절대 오차가 10-6 이내인 경우에만 정답이다.

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