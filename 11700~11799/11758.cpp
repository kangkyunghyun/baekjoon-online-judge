// 11758: CCW
//
// - 문제
// 2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다. (-10,000 ≤ x1, y1, x2, y2, x3, y3 ≤ 10,000) 모든 좌표는 정수이다. P1, P2, P3의 좌표는 서로 다르다.
//
// - 출력
// P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
  int tmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
  if (tmp > 0)
    return 1;
  else if (tmp < 0)
    return -1;
  else
    return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pair<int, int> a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i].first >> a[i].second;
  cout << ccw(a[0].first, a[0].second, a[1].first, a[1].second, a[2].first, a[2].second);
  return 0;
}