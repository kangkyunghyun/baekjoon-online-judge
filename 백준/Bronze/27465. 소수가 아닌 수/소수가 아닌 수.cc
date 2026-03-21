#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (1) {
    if (!isPrime(n)) {
      cout << n;
      break;
    }
    n++;
  }
  return 0;
}