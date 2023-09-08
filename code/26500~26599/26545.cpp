// 26545: Mathematics
//
// - 문제
// A mathematician has stolen your calculator! Luckily, you know how to code and can write a program that adds together numbers. Write a program that adds together a list of integers.
//
// - 입력
// The first line will contain a single integer n that indicates the number of integers to add together. The next n lines will each contain one integer. Your task is to write a program that adds all of the integers together.
//
// - 출력
// Output the resulting integer. The output should be one line containing one integer value.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b = 0;
  cin >> n;
  while (n--) {
    cin >> a;
    b += a;
  }
  cout << b;
  return 0;
}