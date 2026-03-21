#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    sum += (n + 2) * i;
  }
  cout << sum << '\n';
  return 0;
}