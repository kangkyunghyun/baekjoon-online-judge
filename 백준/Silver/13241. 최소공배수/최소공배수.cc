#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int main() {
  long long a, b;
  cin >> a >> b;
  cout << a * b / gcd(a, b) << '\n';
  return 0;
}