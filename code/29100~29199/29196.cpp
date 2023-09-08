// 29196: 소수가 아닌 수 2
//
// - 문제
// 이 대회의 운영진 중 한 명인 KSA 학생은 얼마 전 소수 공포증을 극복했으나 또 다른 소수를 구별할 수 없게 되어 버렸다. KSA의 명예를 지키기 위해 어떤 소수 $k$를 입력받아 $k$를 나타내는 분수 $\cfrac{p}{q}$를 아무거나 구해주자.
// $p$와 $q$는 $10^{9}$ 이하인 양의 정수이며, $k$와 $\cfrac{p}{q}$의 절대오차 또는 상대오차가 $10^{-6}$ 이하면 정답이다.
//
// - 입력
// 첫 번째 줄에 소수 $k$가 주어진다.
//
// - 출력
// 첫 번째 줄에 조건을 만족하는 분수가 존재한다면 YES, 아니라면 NO를 출력한다.
// 만약 그러한 분수가 존재한다면, 두 번째 줄에 두 정수 $p$, $q$를 공백을 사이에 두고 출력한다.
// 정답이 여러 개 존재한다면 그중 아무거나 출력해도 상관없다.
//
// - 제한
// $0 < k < 1$
// $k$는 최대 소수점 아래 여덟 자리까지 주어짐
// 소수 끝에 불필요한 $0$은 주어지지 않음

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string k, tq = "1";
  cin >> k;
  cout << "YES\n";
  int p = stoi(k.substr(2));
  for (int i = 0; i < k.size() - 2; i++)
    tq += '0';
  int q = stoi(tq);
  int g = gcd(p, q);
  cout << p / g << ' ' << q / g;
  return 0;
}