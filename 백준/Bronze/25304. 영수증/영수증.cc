#include <iostream>
using namespace std;

int main() {
  int x, n, a, b, r = 0;
  cin >> x >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    r += a * b;
  }
  if (x == r) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}