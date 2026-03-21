#include <iostream>
using namespace std;

int main() {
  int a, b, c, result, big;
  cin >> a >> b >> c;
  if (a == b && b == c) {
    result = 10000 + a * 1000;
  } else if (a == b) {
    result = 1000 + a * 100;
  } else if (b == c) {
    result = 1000 + b * 100;
  } else if (a == c) {
    result = 1000 + c * 100;
  } else {
    big = a;
    if (b > big) {
      big = b;
    }
    if (c > big) {
      big = c;
    }
    result = big * 100;
  }
  cout << result << '\n';
  return 0;
}