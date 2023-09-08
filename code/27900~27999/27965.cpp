// 27965: N결수
//
// - 문제
// 10진법 상에서 양의 정수 1, 2, 3, ..., N을 이어 붙여 만든 수  \overline{123... N}을 N결수라고 한다.
// 예를 들어 12345는 5결수이고, 12345678910111213은 13결수이다.
// N과 정수 K가 주어졌을 때, N결수를 K로 나눈 나머지를 구하자.
//
// - 입력
// 첫째 줄에 정수 N과 정수 K가 공백으로 구분되어 주어진다. (1 ≤ N ≤ 10^7; 1 ≤ K ≤ 10^9)
//
// - 출력
// 첫째 줄에 N결수를 K로 나눈 나머지를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  string s = "0";
  for (int i = 1; i <= n; i++) {
    s += to_string(i);
    long long num = stoll(s);
    num %= k;
    s = to_string(num);
  }
  cout << s;
  return 0;
}