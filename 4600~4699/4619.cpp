// 4619: 루트
//
// - 문제
// 양의 정수 B와 N이 주어졌을 때, B에 가장 가까운 AN의 정수 A를 찾는 프로그램을 작성하시오. AN은 B보다 작거나, 크거나, 같다.
//
// - 입력
// 입력은 여러 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, B와 N이 주어진다. (1 ≤ B ≤ 1,000,000, 1 ≤ N ≤ 9) 입력의 마지막 줄에는 0이 2개 주어진다.
//
// - 출력
// 각 테스트 케이스에 해당하는 A를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    int b, n;
    cin >> b >> n;
    if (b + n == 0)
      break;
    int ans = 0, a = 1;
    while (1) {
      int curr = abs(b - (int)pow(a, n));
      int prev = abs(b - (int)pow(ans, n));
      if (curr < prev)
        ans = a;
      else
        break;
      a++;
    }
    cout << ans << '\n';
  }
  return 0;
}