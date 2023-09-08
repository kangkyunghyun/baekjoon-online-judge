// 10093: 숫자
//
// - 문제
// 두 양의 정수가 주어졌을 때, 두 수 사이에 있는 정수를 모두 출력하는 프로그램을 작성하시오.
//
// - 입력
// 두 정수 A와 B가 주어진다.
//
// - 출력
// 첫째 줄에 두 수 사이에 있는 수의 개수를 출력한다.
// 둘째 줄에는 두 수 사이에 있는 수를 오름차순으로 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  if (a > b) {
    long long temp = a;
    a = b;
    b = temp;
  }
  if (a != b) {
    cout << b - a - 1 << '\n';
    for (long long i = a + 1; i < b; i++)
      cout << i << ' ';
  } else
    cout << 0;
  cout << '\n';
  return 0;
}