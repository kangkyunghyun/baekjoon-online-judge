#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int i = 0; i < 3; i++) {
    int h, m, s, hh, mm, ss;
    cin >> h >> m >> s >> hh >> mm >> ss;
    int ah = hh - h;
    int am = mm - m;
    int as = ss - s;
    while (as < 0) {
      as += 60;
      am--;
    }
    while (am < 0) {
      am += 60;
      ah--;
    }
    cout << ah << ' ' << am << ' ' << as << '\n';
  }
  return 0;
}