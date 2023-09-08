// 22193: Multiply
//
// - 문제
// Write a program that computes a product of two non-negative integers A and B.
// The integers are represented in decimal notation and have N and M digits, respectively.
//
// - 입력
// The first line contains the lengths N and M, separated by a space.
// A is given on the second and B on the third line. The numbers will not have leading zeros.
//
// - 출력
// Output the product of A and B without leading zeros.
//
// - 제한
// 1 ≤ N, M ≤ 50 000

#include <iostream>
using namespace std;

int main() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  cout << a * b << '\n';
  return 0;
}