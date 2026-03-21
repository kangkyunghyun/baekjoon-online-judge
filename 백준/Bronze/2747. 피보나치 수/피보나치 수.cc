#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a = 0, b = 1;
  for (int i = 1; i <= n; i++) {
    int temp;
    temp = a + b;
    a = b;
    b = temp;
  }
  cout << a << '\n';
  return 0;
}