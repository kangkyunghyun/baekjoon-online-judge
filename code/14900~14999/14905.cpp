// 14905: 소수 4개의 합
//
// - 문제
// 모든 자연수를 4개의 소수의 합으로 나타낼 수 있을까? 이 물음에 대한 답은 '8 이상의 모든 자연수에 대해 그렇다'이지만, 데이빗은 그 사실을 알지 못했다. 데이빗은 프로그램을 돌려 4개의 소수의 합으로 표현할 수 없는 수를 찾아내 보기로 했다. 소수는 "두 개의 다른 자연수로만 나눠 떨어지는 자연수"이다. 예를 들어, 37은 37과 1로만 나눠 떨어지므로 소수이다.
//
// - 입력
// 입력 파일에는 한 줄에 하나씩 1 이상 100,000,000 이하의 자연수가 주어진다.
//
// - 출력
// 입력 라인에 맞춰, 주어진 조건에 맞는 4개의 소수를 한 줄에 출력한다. 입력된 수가 소수 4개의 합으로 표현될 수 없으면 “Impossible.”이라 출력한다. 답은 여러 개가 있을 수 있다. 하지만 더해서 입력된 수가 나오는 소수 4개라면 모두 정답이다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> sieve(50000000, 1), prime;
  sieve[0] = 0, sieve[1] = 0;
  for (int i = 2; i * i <= 50000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 50000000; j += i)
        sieve[j] = 0;
    }
  int n;
  while (cin >> n) {
    if (n < 8) {
      cout << "Impossible.\n";
      continue;
    }
    if (n % 2) {
      n -= 5;
      cout << "2 3 ";
    } else {
      n -= 4;
      cout << "2 2 ";
    }
    for (int i : prime)
      if (sieve[n - i]) {
        cout << i << ' ' << n - i << '\n';
        break;
      }
  }
  return 0;
}