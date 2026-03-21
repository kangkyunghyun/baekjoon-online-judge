#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((a == 8 || a == 9) && (d == 8 || d == 9) && (b == c) ? "ignore" : "answer");
}