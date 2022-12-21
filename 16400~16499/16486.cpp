// 16486: 운동장 한 바퀴
//
// - 문제
// 세연이네 학교 운동장은 아래와 같다.
// 위의 그림에서 영역 A와 B는 반원이며, 영역 C는 직사각형이다. 영역 C의 가로의 길이를 d1, 영역 A의 반지름의 길이 d2의 값이 주어지면 운동장의 한 바퀴 둘레를 알아내는 프로그램을 작성하시오. (단, 이 문제에서는 π (원주율)의 값을 3.141592라고 한다.)
//
// - 입력
// 첫째 줄에 d1의 값이 주어진다. 둘째 줄에는 d2의 값이 주어진다. (d1, d2의 값은 100,000 이하의 양의 정수)
//
// - 출력
// 첫째 줄에 문제에서 요구하는 정답을 출력한다. 절대/상대 오차는 10^-6 까지 허용한다.

#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  double d1, d2;
  cin >> d1 >> d2;
  double ans = 2 * d1 + 2 * PI * d2;
  cout.precision(6);
  cout << fixed << ans;
  return 0;
}