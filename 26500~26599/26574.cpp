// 26574: Copier
//
// - 문제
// Your copier broke down last week, and you need to copy a list of numbers for a class project due tomorrow! Luckily, you can use your computer to copy the numbers for you. Given a list of numbers, each on their own line, print out the number, a space, and then another copy of the number.
//
// - 입력
// The first line will contain a single integer n that indicates the number of numbers to follow, each on their own line. The next n lines will each contain a single number.
//
// - 출력
// For each of the n lines, print out the original number and a copy of the number, with one space of separation.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a;
  cin >> n;
  while (n--) {
    cin >> a;
    cout << a << ' ' << a << '\n';
  }
  return 0;
}