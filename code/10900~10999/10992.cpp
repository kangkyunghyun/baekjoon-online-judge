// 10992: 별 찍기 - 17
//
// - 문제
// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
//
// - 출력
// 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = n - i - 1; j > 0; j--)
      cout << ' ';
    if (i == 0)
      cout << '*';
    else if (i == n - 1) {
      for (int j = 0; j < 2 * n - 1; j++)
        cout << '*';
    } else {
      cout << '*';
      for (int j = 0; j < 2 * i - 1; j++)
        cout << ' ';
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}