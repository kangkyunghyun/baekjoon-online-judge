#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << x + y - gcd(x, y);
  return 0;
}