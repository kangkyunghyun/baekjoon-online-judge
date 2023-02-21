// 1016: 제곱 ㄴㄴ 수
//
// - 문제
// 어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.
//
// - 입력
// 첫째 줄에 두 정수 min과 max가 주어진다.
//
// - 출력
// 첫째 줄에 min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long min, max;
  cin >> min >> max;
  vector<long long> sieve(1000001, 1);
  for (long long i = 2; i * i <= max; i++) {
    long long n = min / (i * i);
    if (min % (i * i))
      n++;
    while (n * i * i <= max) {
      sieve[n * i * i - min] = 0;
      n++;
    }
  }
  cout << accumulate(sieve.begin(), sieve.begin() + max - min + 1, 0) << '\n';
  return 0;
}