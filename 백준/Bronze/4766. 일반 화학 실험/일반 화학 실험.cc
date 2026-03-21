#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double a, b;
  cin >> a;
  while (cin >> b) {
    if (b == 999)
      break;
    cout.precision(2);
    cout << fixed << b - a << '\n';
    a = b;
  }
  return 0;
}