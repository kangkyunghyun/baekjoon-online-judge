#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  double ans = max(a * (double)b / c, (double)a / b * c);
  cout << (int)ans << '\n';
  return 0;
}