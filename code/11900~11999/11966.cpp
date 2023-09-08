// 11966: 2의 제곱인가?
//
// - 문제
// 자연수 N이 주어졌을 때, 2의 제곱수면 1을 아니면 0을 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 2^30)이 주어진다.
//
// - 출력
// N이 2의 제곱수면 1을 아니면 0을 출력하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (log2(n) - (int)log2(n) == 0);
  return 0;
}