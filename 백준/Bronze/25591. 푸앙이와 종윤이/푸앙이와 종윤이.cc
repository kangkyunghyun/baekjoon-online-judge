#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int i1, i2;
  cin >> i1 >> i2;
  int a = 100 - i1, b = 100 - i2, c = 100 - a - b, d = a * b;
  int q = d / 100, r = d % 100;
  cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n'
       << c + q << ' ' << r << '\n';
  return 0;
}