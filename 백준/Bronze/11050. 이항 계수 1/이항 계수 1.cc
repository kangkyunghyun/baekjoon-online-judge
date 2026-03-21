#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++)
    result *= i;
  return result;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << factorial(n) / factorial(n - k) / factorial(k);
  return 0;
}