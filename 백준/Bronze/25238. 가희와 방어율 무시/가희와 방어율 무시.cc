#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a * (100 - b) / 100 >= 100) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
  }
  return 0;
}