// 17103: 골드바흐 파티션
//
// - 문제
// 골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.
// 짝수 N을 두 소수의 합으로 나타내는 표현을 골드바흐 파티션이라고 한다. 짝수 N이 주어졌을 때, 골드바흐 파티션의 개수를 구해보자. 두 소수의 순서만 다른 것은 같은 파티션이다.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수 T (1 ≤ T ≤ 100)가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 N은 짝수이고, 2 < N ≤ 1,000,000을 만족한다.
//
// - 출력
// 각각의 테스트 케이스마다 골드바흐 파티션의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 1000000; j += i)
        sieve[j] = 0;
    }
  int t, n;
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < prime.size(); i++) {
      if (n - prime[i] < prime[i])
        break;
      if (sieve[n - prime[i]])
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}