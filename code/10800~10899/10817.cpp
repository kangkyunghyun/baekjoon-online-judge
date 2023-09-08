// 10817: 세 수
//
// - 문제
// 세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)
//
// - 출력
// 두 번째로 큰 정수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  sort(a, a + 3);
  cout << a[1];
  return 0;
}