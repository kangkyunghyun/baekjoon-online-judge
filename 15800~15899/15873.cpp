// 15873: 공백 없는 A+B
//
// - 문제
// 자연수 A, B가 주어지면 A+B를 구하는 프로그램을 작성하시오.
//
// - 입력
// 자연수 A, B (0 < A, B ≤ 10)가 첫 번째 줄에 주어진다. 단, 두 수의 사이에는 공백이 주어지지 않는다. 두 수의 앞에 불필요한 0이 붙는 경우는 없다.
//
// - 출력
// 첫 번째 줄에 A+B의 값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int a, b;
  if (str.length() == 2) {
    a = str[0] - '0';
    b = str[1] - '0';
  } else if (str.length() == 3) {
    if (str[1] == '0') {
      a = 10;
      b = str[2] - '0';
    } else if (str[2] == '0') {
      a = str[0] - '0';
      b = 10;
    }
  } else if (str.length() == 4) {
    a = 10;
    b = 10;
  }
  cout << a + b << '\n';
  return 0;
}