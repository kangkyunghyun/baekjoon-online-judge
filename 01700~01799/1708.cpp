// 1708: 볼록 껍질
//
// - 문제
// 다각형의 임의의 두 꼭짓점을 연결하는 선분이 항상 다각형 내부에 존재하는 다각형을 볼록 다각형이라고 한다. 아래 그림에서 (a)는 볼록 다각형이며, (b)는 볼록 다각형이 아니다.
// 조금만 생각해 보면 다각형의 모든 내각이 180도 이하일 때 볼록 다각형이 된다는 것을 알 수 있다. 편의상 이 문제에서는 180도 미만인 경우만을 볼록 다각형으로 한정하도록 한다.
// 2차원 평면에 N개의 점이 주어졌을 때, 이들 중 몇 개의 점을 골라 볼록 다각형을 만드는데, 나머지 모든 점을 내부에 포함하도록 할 수 있다. 이를 볼록 껍질 (CONVEX HULL) 이라 한다. 아래 그림은 N=10인 경우의 한 예이다.
// 점의 집합이 주어졌을 때, 볼록 껍질을 이루는 점의 개수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 점의 개수 N(3 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 점의 x좌표와 y좌표가 빈 칸을 사이에 두고 주어진다. 주어지는 모든 점의 좌표는 다르다. x좌표와 y좌표의 범위는 절댓값 40,000을 넘지 않는다. 입력으로 주어지는 다각형의 모든 점이 일직선을 이루는 경우는 없다.
//
// - 출력
// 첫째 줄에 볼록 껍질을 이루는 점의 개수를 출력한다.
// 볼록 껍질의 변에 점이 여러 개 있는 경우에는 가장 양 끝 점만 개수에 포함한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
  ll x, y;
};

int n;
vector<Point> p;
stack<Point> s;

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
  s.push(p[0]);
  s.push(p[1]);
  for (int i = 2; i < n; i++) {
    while (s.size() >= 2) {
      Point second = s.top();
      s.pop();
      Point first = s.top();
      if (ccw(first, second, p[i]) > 0) {
        s.push(second);
        break;
      }
    }
    s.push(p[i]);
  }
  cout << s.size();
  return 0;
}