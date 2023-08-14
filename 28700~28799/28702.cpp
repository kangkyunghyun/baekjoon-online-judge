// 28702: FizzBuzz
//
// - 문제
// FizzBuzz 문제는 i = 1, 2, \cdots 에 대해 다음 규칙에 따라 문자열을 한 줄에 하나씩 출력하는 문제입니다.
// - i가 3의 배수이면서 5의 배수이면 “FizzBuzz”를 출력합니다.
// - i가 3의 배수이지만 5의 배수가 아니면 “Fizz”를 출력합니다.
// - i가 3의 배수가 아니지만 5의 배수이면 “Buzz”를 출력합니다.
// - i가 3의 배수도 아니고 5의 배수도 아닌 경우 i를 그대로 출력합니다.
// FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열이 주어집니다. 이때, 이 세 문자열 다음에 올 문자열은 무엇일까요?
//
// - 입력
// FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열이 한 줄에 하나씩 주어집니다. 각 문자열의 길이는 8 이하입니다. 입력이 항상 FizzBuzz 문제에서 연속으로 출력된 세 개의 문자열에 대응됨이 보장됩니다.
//
// - 출력
// 연속으로 출력된 세 개의 문자열 다음에 올 문자열을 출력하세요. 여러 문자열이 올 수 있는 경우, 아무거나 하나 출력하세요.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b, c;
  cin >> a >> b >> c;
  if (c[0] >= 48 && c[0] <= 57) {
    int x = stoi(c) + 1;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  } else if (b[0] >= 48 && b[0] <= 57) {
    int x = stoi(b) + 2;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  } else if (a[0] >= 48 && a[0] <= 57) {
    int x = stoi(a) + 3;
    if (x % 3 == 0) {
      if (x % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (x % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << x;
    }
  }
  return 0;
}