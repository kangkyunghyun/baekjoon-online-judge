#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    Sx += x;
    Sy += y;
    Sxx += x * x;
    Sxy += x * y;
  }
  double a = (double)(n * Sxy - Sx * Sy) / (n * Sxx - Sx * Sx);
  double b = (double)(Sy - a * Sx) / n;
  cout.precision(9);
  if (isnan(a) && isnan(b))
    cout << "EZPZ";
  else
    cout << fixed << a << ' ' << b;
  return 0;
}