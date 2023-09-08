// 1644: 소수의 연속합
//
// - 문제
// 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.
// 3 : 3 (한 가지)
// 41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
// 53 : 5+7+11+13+17 = 53 (두 가지)
// 하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.
// 자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)
//
// - 출력
// 첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  vector<int> sieve(n + 1, 1), prime;
  for (int i = 2; i <= n; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= n; j += i)
        sieve[j] = 0;
    }
  for (int i = 0; i < prime.size(); i++) {
    int sum = 0;
    for (int j = i; j < prime.size(); j++) {
      sum += prime[j];
      if (sum == n)
        ans++;
      else if (sum > n)
        break;
    }
  }
  cout << ans;
  return 0;
}