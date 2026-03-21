#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  long long a, b;
  cin >> a >> b;
  int t = gcd(a, b);
  for (int i = 0; i < t; i++)
    cout << 1;
  return 0;
}