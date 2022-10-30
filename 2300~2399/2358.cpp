// 2358: 평행선
//
// - 문제
// 평면상에 n개의 점이 있다. 이 점들 중에 서로 다른 두 점을 선택하면 하나의 직선이 만들어진다.
// 이와 같이 직선을 만들었을 때, x축 또는 y축에 평행한 직선이 몇 개나 되는지 알아내는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다. 다음 n개의 줄에는 각 점의 좌표가 주어진다.
// 만약 입력에 서로 같은 두 점이 주어지면, 그 두 점을 이용하여 직선을 만들 수 있다. 좌표는 절댓값이 231보다 작은 정수이다.
//
// - 출력
// 첫째 줄에 답을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x, y, ans = 0;
  cin >> n;
  map<int, int> mapX;
  map<int, int> mapY;
  while (n--) {
    cin >> x >> y;
    mapX[x]++;
    mapY[y]++;
  }
  for (auto i : mapX)
    if (i.second >= 2)
      ans++;
  for (auto i : mapY)
    if (i.second >= 2)
      ans++;
  cout << ans << '\n';
  return 0;
}