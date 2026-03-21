#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> sieve(50000000, 1), prime;
  sieve[0] = 0, sieve[1] = 0;
  for (int i = 2; i * i <= 50000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 50000000; j += i)
        sieve[j] = 0;
    }
  int n;
  while (cin >> n) {
    if (n < 8) {
      cout << "Impossible.\n";
      continue;
    }
    if (n % 2) {
      n -= 5;
      cout << "2 3 ";
    } else {
      n -= 4;
      cout << "2 2 ";
    }
    for (int i : prime)
      if (sieve[n - i]) {
        cout << i << ' ' << n - i << '\n';
        break;
      }
  }
  return 0;
}