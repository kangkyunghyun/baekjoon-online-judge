#include <bits/stdc++.h>
using namespace std;

vector<long long> sieve(2000001, 1), prime;

bool isPrime(long long n) {
  if (n <= 2000000)
    return sieve[n];
  else
    for (int i : prime)
      if (!(n % i))
        return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  for (int i = 2; i <= 2000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 2000000; j += i)
        sieve[j] = 0;
    }
  int t;
  cin >> t;
  while (t--) {
    long long a, b, s;
    cin >> a >> b;
    s = a + b;
    if (s == 2 || s == 3)
      cout << "NO\n";
    else if (s % 2 == 0)
      cout << "YES\n";
    else {
      if (isPrime(s - 2))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}