#include <iostream>
using namespace std;

int main() {
  string a;
  cin >> a;
  double b = 0;
  cout << fixed;
  cout.precision(1);
  if (a[0] == 'A') {
    b += 4;
  } else if (a[0] == 'B') {
    b += 3;
  } else if (a[0] == 'C') {
    b += 2;
  } else if (a[0] == 'D') {
    b += 1;
  }
  if (a[1] == '+') {
    b += 0.3;
  } else if (a[1] == '-') {
    b -= 0.3;
  }
  cout << b << '\n';
}