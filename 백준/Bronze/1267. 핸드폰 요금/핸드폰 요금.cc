#include <iostream>
using namespace std;

int main() {
  int n, time, y = 0, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> time;
    y += 10 * (time / 30 + 1);
    m += 15 * (time / 60 + 1);
  }
  if (y > m) {
    cout << "M " << m << '\n';
  } else if (m > y) {
    cout << "Y " << y << '\n';
  } else {
    cout << "Y M " << m << '\n';
  }
  return 0;
}