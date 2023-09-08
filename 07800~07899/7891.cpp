// 7891: Can you add this?
//
// - 문제
// Given two integers, calculate and output their sum.
//
// - 입력
// The input contains several test cases. The first line contains and integer t (t ≤ 100) denoting the number of test cases. Then t tests follow, each of them consisiting of two space separated integers x and y (−10^9 ≤ x, y ≤ 10^9).
//
// - 출력
// For each test case output output the sum of the corresponding integers.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    cout << a + b << '\n';
  }
  return 0;
}