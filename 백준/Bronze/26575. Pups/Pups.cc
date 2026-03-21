#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    double d, f, p;
    cin >> d >> f >> p;
    cout.precision(2);
    cout << fixed << '$' << d * f * p << '\n';
  }
  return 0;
}