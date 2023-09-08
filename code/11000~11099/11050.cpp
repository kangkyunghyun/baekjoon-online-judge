// 11050: 이항 계수 1
//
// - 문제
// 자연수 N과 정수 K가 주어졌을 때 이항 계수 (NK)를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)
//
// - 출력
// (NK)를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++)
    result *= i;
  return result;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << factorial(n) / factorial(n - k) / factorial(k);
  return 0;
}