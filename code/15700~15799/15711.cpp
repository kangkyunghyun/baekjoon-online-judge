// 15711: 환상의 짝꿍
//
// - 문제
// 환상의 나라 디디랜드에서는 인연의 증표로 끈을 하나씩 가지고 있다. 그들은 지극히 평범한 방법으로 이 끈을 이용하여 어떤 두 사람이 환상의 짝꿍인지 판단하는데, 두 사람의 끈을 서로 이어붙이고 그 끈을 다시 길이가 소수인 끈 두개로 정확히 나눌 수 있다면 두 사람은 환상의 짝꿍이라고 한다. 하지만 그들은 길이가 소수인 두개의 끈으로 나눌 수 있는지 판단하는 것이 어려워서 대부분 서로가 인연임을 모르고 그냥 지나간다고 한다. 애석하게도...
// 그런 그들을 위해서 어떤 두 사람이 환상의 짝꿍인지 판단하는 프로그램을 작성하라.
// 편의상 두 사람의 끈을 이어붙일 때와 나눌 때 손실되는 끈의 길이는 0이라고 가정한다.
//
// - 입력
// 첫째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 500)가 주어진다.
// 둘째 줄부터 T개 줄에 두 사람이 가지고 있는 끈의 길이를 나타내는 정수 A, B가 공백으로 구분되어 주어진다. (1 ≤ A, B ≤ 2 × 10^12)
//
// - 출력
// 각 테스트 케이스마다 한 줄씩 두 사람의 끈을 이어붙이고 그 끈을 다시 길이가 소수인 두개의 끈으로 정확히 나눌 수 있다면 YES, 불가능하면 NO를 출력하라.

#include <bits/stdc++.h>
using namespace std;

vector<long long> sieve(2000001, 1), prime;

bool isPrime(long long n) {
  if (n <= 2000000)
    return sieve[n];
  else
    for (int i : prime)
      if (!(n % i))
        return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  for (int i = 2; i <= 2000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 2000000; j += i)
        sieve[j] = 0;
    }
  int t;
  cin >> t;
  while (t--) {
    long long a, b, s;
    cin >> a >> b;
    s = a + b;
    if (s == 2 || s == 3)
      cout << "NO\n";
    else if (s % 2 == 0)
      cout << "YES\n";
    else {
      if (isPrime(s - 2))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}