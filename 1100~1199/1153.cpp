// 1153: 네 개의 소수
//
// - 문제
// 임의의 자연수가 주어지면, 이를 네 개의 소수의 합으로 분해하는 프로그램을 작성하시오. 예를 들어 38 = 5 + 7 + 13 + 13이 된다.
//
// - 입력
// 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
//
// - 출력
// 첫째 줄에 네 개의 소수를 빈 칸을 사이에 두고 순서대로 출력한다. 불가능한 경우는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  if (n < 8) {
    cout << -1;
    return 0;
  }
  vector<int> sieve(n + 1, 1), prime, ans;
  for (int i = 2; i * i <= n; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= n; j += i)
        sieve[j] = 0;
    }
  if (n % 2) {
    ans.push_back(2);
    ans.push_back(3);
    n -= 5;
  } else {
    ans.push_back(2);
    ans.push_back(2);
    n -= 4;
  }
  for (int i = 0; i < prime.size(); i++)
    if (sieve[n - prime[i]]) {
      ans.push_back(prime[i]);
      ans.push_back(n - prime[i]);
      break;
    }
  for (int i : ans)
    cout << i << ' ';
  return 0;
}