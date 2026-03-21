#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long min, max;
  cin >> min >> max;
  vector<long long> sieve(1000001, 1);
  for (long long i = 2; i * i <= max; i++) {
    long long n = min / (i * i);
    if (min % (i * i))
      n++;
    while (n * i * i <= max) {
      sieve[n * i * i - min] = 0;
      n++;
    }
  }
  cout << accumulate(sieve.begin(), sieve.begin() + max - min + 1, 0) << '\n';
  return 0;
}