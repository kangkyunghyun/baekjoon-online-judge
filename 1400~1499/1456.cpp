// 1456: 거의 소수
//
// - 문제
// 어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.
// 두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.
//
// - 입력
// 첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다.
//
// - 출력
// 첫째 줄에 총 몇 개가 있는지 출력한다.
//
// - 제한
// 1 ≤ A ≤ B ≤ 10^14

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 10000000; j += i)
        sieve[j] = 0;
    }
  long long a, b, ans = 0;
  cin >> a >> b;
  for (int i : prime) {
    long long tmp = i;
    while (tmp <= b / i) {
      tmp *= i;
      if (tmp >= a)
        ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}