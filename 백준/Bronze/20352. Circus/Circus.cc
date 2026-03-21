#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  double a;
  cin >> a;
  double r = sqrt(a / 3.141592);
  cout.precision(6);
  cout << fixed << 2 * 3.141592 * r;
  return 0;
}