// 1124: 언더프라임
//
// - 문제
// 자연수 X를 소인수분해하면, 곱해서 X가 되는 소수의 목록을 얻을 수 있다. 예를 들어, 12 = 2 × 2 × 3이다. 1은 소수가 아니다.
// 어떤 수 X를 소인수분해 해서 구한 소수의 목록의 길이가 소수이면, 그 수를 언더프라임 이라고 한다. 12는 목록에 포함된 소수의 개수가 3개이고, 3은 소수이니 12는 언더프라임이다.
// 두 정수 A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 정수 중에서 언더프라임인 것의 개수를 구해보자.
//
// - 입력
// 첫째 줄에 두 정수 A와 B가 주어진다.
//
// - 출력
// 첫째 줄에 A보다 크거나 같고, B보다 작거나 같은 언더프라임 개수를 출력한다.
//
// - 제한
// 2 ≤ A ≤ B ≤ 100,000

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, ans = 0;
  cin >> a >> b;
  vector<int> sieve(100001, 1), prime;
  for (int i = 2; i <= 100000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 100000; j += i)
        sieve[j] = 0;
    }
  for (int i = a; i <= b; i++) {
    vector<int> check;
    int x = i;
    for (int j : prime) {
      while (x % j == 0) {
        check.push_back(j);
        x /= j;
      }
      if (x < 2)
        break;
    }
    if (isPrime(check.size()))
      ans++;
  }
  cout << ans;
  return 0;
}