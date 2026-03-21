#include <iostream>
using namespace std;

int main() {
  int n, d, m, y, young_y = 1900, young_m = 1, young_d = 1, old_y = 2022, old_m = 9, old_d = 17;
  string name, old, young;
  cin >> n;
  while (n--) {
    cin >> name >> d >> m >> y;
    if (y > young_y) {
      young_y = y;
      young_m = m;
      young_d = d;
      young = name;
    } else if (y == young_y && m > young_m) {
      young_y = y;
      young_m = m;
      young_d = d;
      young = name;
    } else if (y == young_y && m == young_m && d > young_d) {
      young_y = y;
      young_m = m;
      young_d = d;
      young = name;
    }
    if (y < old_y) {
      old_y = y;
      old_m = m;
      old_d = d;
      old = name;
    } else if (y == old_y && m < old_m) {
      old_y = y;
      old_m = m;
      old_d = d;
      old = name;
    } else if (y == old_y && m == old_m && d < old_d) {
      old_y = y;
      old_m = m;
      old_d = d;
      old = name;
    }
  }
  cout << young << '\n'
       << old << '\n';
  return 0;
}