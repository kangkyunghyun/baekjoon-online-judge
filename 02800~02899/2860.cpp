// 2860: 종이에 숫자 쓰기
//
// - 문제
// 상근이는 종이에 숫자를 쓰려고 한다. 종이에는 1~5 사이의 숫자를 1개만 쓸 수 있고, 상근이는 종이를 무한개 가지고 있다.
// 열심히 종이에 숫자를 쓴 다음에, 종이에 쓴 숫자의 평균을 P와 같게 만들려고 한다.
// 이때, 사용한 종이의 개수를 최소로 하려고 한다. P가 주어졌을 때, 각 숫자를 총 몇 번 쓰는지 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 P가 주어진다. P는 1보다 크거나 같고, 5보다 작거나 같으며 소수점 1자리 ~ 9자리이다.
//
// - 출력
// 첫째 줄에 5개의 음이 아닌 정수를 출력한다. 첫 번째 숫자는 1의 개수, 두 번째 숫자는 2의 개수, ..., 마지막 숫자는 5의 개수이다. 가능한 방법이 여러개라면 아무거나 출력한다.

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string p;
  cin >> p;
  long long n = 0, m = 1;
  for (int i = p.size() - 1; i >= 0; i--) {
    if (p[i] == '.')
      continue;
    n += (p[i] - '0') * m;
    m *= 10;
  }
  m /= 10;
  long long g = gcd(n, m);
  n /= g;
  m /= g;
  vector<long long> ans(7, 0);
  long long a = n / m;
  long long b = n % m;
  ans[a] = m - b;
  ans[a + 1] = b;
  for (int i = 1; i <= 5; i++)
    cout << ans[i] << ' ';
  return 0;
}