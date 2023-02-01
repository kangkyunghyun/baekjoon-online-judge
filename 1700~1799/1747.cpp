// 1747: 소수&팰린드롬
//
// - 문제
// 어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다. 예를 들어 79,197과 324,423 등이 팰린드롬 수이다.
// 어떤 수 N (1 ≤ N ≤ 1,000,000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N이 주어진다.
//
// - 출력
// 첫째 줄에 조건을 만족하는 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int check(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - 1 - i])
      return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 10000000; j += i)
        sieve[j] = 0;
    }
  for (int i : prime)
    if (i >= n && check(i)) {
      cout << i;
      return 0;
    }
  return 0;
}