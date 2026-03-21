#include <iostream>
using namespace std;

int main() {
  int h, m, t;
  cin >> h >> m >> t;
  m += t;
  h += m / 60;
  m = m % 60;
  if (h >= 24) {
    h -= 24;
  }
  cout << h << ' ' << m << '\n';
  return 0;
}