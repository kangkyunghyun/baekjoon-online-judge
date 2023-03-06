// 14941: 호기심
//
// - 문제
// 남규는 호기심이 많다. 호기심이 많은 남규는 a와 b 사이의 소수들의 합과 차를 이용한 특수한 함수 F를 만들었다. 남규는 이 특수한 함수의 결과값을 알고 싶다.
// 함수 F(a,b)는 a와 b 사이의 소수를 순서대로 다음과 같은 규칙에 따라 계산하고, 그 값을 반환한다.
// 3×A1 - A2 + 3×A3 - A4 + 3×A5 - A6 ..... An (a ≤ A1 < … < An ≤ b , Ai는 소수이다.)
// 질문이 F(3, 7) 이라면 3과 7 사이에는 3, 5, 7 총 3개의 소수가 있고, 규칙에 따라 계산한 결과는
// 3×3 - 5 + 3×7 = 25 이다.
//
// - 입력
// 첫 줄에는 질문의 개수 n이 주어진다. 다음 줄 부터 차례대로 함수의 입력 a, b가 주어진다. (1 ≤ a ≤ b ≤ 105) 또한 남규는 호기심이 많기 때문에 매우 많은 질문을 한다. 따라서 질문의 수 n은 최대 105 개이다.
//
// - 출력
// 남규가 물어본 질문 a, b에 대한 답변 F(a, b)을 각 줄에 하나씩 순서대로 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> sieve(500001, 1), prime;
  for (int i = 2; i <= 500000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 500000; j += i)
        sieve[j] = 0;
    }
  while (n--) {
    int a, b, cnt = 1, ans = 0;
    cin >> a >> b;
    auto s = lower_bound(prime.begin(), prime.end(), a);
    auto e = upper_bound(prime.begin(), prime.end(), b);
    for (auto it = s; it != e; it++, cnt++)
      if (cnt % 2)
        ans += 3 * *it;
      else
        ans -= *it;
    cout << ans << '\n';
  }
  return 0;
}