#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a;
  for (int i = 0; i < 9; i++) {
    cin >> b;
    a -= b;
  }
  cout << a << '\n';
  return 0;
}