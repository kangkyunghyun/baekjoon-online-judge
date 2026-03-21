#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int d1, d2, x;
  cin >> d1 >> d2 >> x;
  if (d1 > d2)
    swap(d1, d2);
  double p = (double)(100 - x) / x;
  cout.precision(6);
  cout << fixed << (p + 1) / (p * d2 / d1 + 1) * d2;
  return 0;
}