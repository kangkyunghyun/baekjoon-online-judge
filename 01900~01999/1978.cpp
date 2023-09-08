// 1978: 소수 찾기
//
// - 문제
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
//
// - 출력
// 주어진 수들 중 소수의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, result = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    int cnt = 0;
    for (int j = 1; j < a; j++) {
      if (a % j == 0)
        cnt++;
    }
    if (cnt == 1)
      result++;
  }
  cout << result << '\n';
  return 0;
}