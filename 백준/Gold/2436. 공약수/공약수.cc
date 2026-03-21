#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int g, l;
  cin >> g >> l;
  int mul = l / g;
  int ansA = 0, ansB = 0;
  for (int i = 1; i <= sqrt(mul); i++)
    if (mul % i == 0) {
      int a = i, b = mul / i;
      if (gcd(a, b) == 1)
        if (ansA == 0 || ansA + ansB > a + b) {
          ansA = a;
          ansB = b;
        }
    }
  cout << ansA * g << ' ' << ansB * g << '\n';
  return 0;
}