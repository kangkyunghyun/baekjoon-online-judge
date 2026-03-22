#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, nc4 = 1;
  cin >> n;
  for (int i = n; i > n - 4; i--)
    nc4 *= i;
  cout << nc4 / 24 << '\n';
  return 0;
}