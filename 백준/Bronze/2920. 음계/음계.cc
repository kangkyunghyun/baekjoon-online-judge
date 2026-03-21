#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f, g, h;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  if (a == 1 && b == 2 && c == 3 && d == 4 && e == 5 && f == 6 && g == 7 && h == 8) {
    cout << "ascending" << '\n';
  } else if (a == 8 && b == 7 && c == 6 && d == 5 && e == 4 && f == 3 && g == 2 && h == 1) {
    cout << "descending" << '\n';
  } else {
    cout << "mixed" << '\n';
  }
  return 0;
}