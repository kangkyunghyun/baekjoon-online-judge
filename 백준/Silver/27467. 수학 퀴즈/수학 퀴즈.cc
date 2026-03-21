#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double p = 0, q = 0;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    while (x > 3) {
      x %= 3;
    }
    if (x == 1) {
      p++;
    } else if (x == 2) {
      p--;
      q--;
    } else {
      q++;
    }
  }
  cout.precision(10);
  cout << fixed << p << ' ' << q << '\n';
  return 0;
}