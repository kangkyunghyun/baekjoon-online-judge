// 27323: 직사각형
//
// - 문제
// 정수 A, B 가 주어진다. 세로 길이가 A cm, 가로 길이가 B cm 인 아래와 같은 직사각형의 넓이를 cm2 단위로 구하시오.
//
// - 입력
// 표준 입력에 다음과 같은 형태로 입력이 주어진다.
// A
// B
//
// - 출력
// 세로 길이가 A cm, 가로 길이가 B cm인 직사각형의 넓이를 cm2 단위로 구하고, 단위 (cm2)를 생략하여 출력한다.
//
// - 제한
// 1 ≦ A ≦ 100.
// 1 ≦ B ≦ 100.
// A, B 는 정수이다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a * b;
  return 0;
}