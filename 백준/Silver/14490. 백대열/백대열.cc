#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int n, m;
  scanf("%d:%d", &n, &m);
  int g = gcd(n, m);
  printf("%d:%d", n / g, m / g);
  return 0;
}