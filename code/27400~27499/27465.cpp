// 27465: 소수가 아닌 수
//
// - 문제
// 이 대회의 운영진 중 한 명인 KSA 학생은 17시와 19시를 구별할 수 없다. 이는 당연하게도 17과 19가 모두 소수이기 때문일 것이다. 시간을 제대로 구별해서 KSA의 명예를 지키기 위해 정수 N을 입력받아서 소수가 아닌 N 이상의 정수를 아무거나 구해주자.
//
// - 입력
// 첫 번째 줄에 정수 N이 주어진다.
//
// - 출력
// 문제의 정답을 출력한다. 정답은 10^{9} 이하여야 한다.
// 정답이 여러 개 존재한다면 아무거나 출력해도 상관없다.
//
// - 제한
//  1 ≤ N ≤ 10^{9} 

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
  cin.tie(NULL);
  int n;
  cin >> n;
  while (1) {
    if (!isPrime(n)) {
      cout << n;
      break;
    }
    n++;
  }
  return 0;
}