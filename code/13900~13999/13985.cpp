// 13985: Equality
//
// - 문제
// You are grading an arithmetic quiz. The quiz asks a student for the sum of the numbers. Determine if the student taking the quiz got the question correct.
//
// - 입력
// The first and the only line of input contains a string of the form:
// a + b = c
// It is guaranteed that a, b, and c are single-digit positive integers. The input line will have exactly 9 characters, formatted exactly as shown, with a single space separating each number and arithmetic operator.
//
// - 출력
// Print, on a single line, YES if the sum is correct; otherwise, print NO.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, ans;
  char op, temp;
  cin >> a >> op >> b >> temp >> c;
  switch (op) {
  case '+':
    ans = a + b;
    break;
  case '-':
    ans = a + -b;
    break;
  case '*':
    ans = a * b;
    break;
  case '/':
    ans = a / b;
    break;
  }
  if (ans == c)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}