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
  cin.tie(NULL), cout.tie(NULL);
  int a, b, ans = 0;
  cin >> a >> b;
  vector<int> sieve(100001, 1), prime;
  for (int i = 2; i <= 100000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 100000; j += i)
        sieve[j] = 0;
    }
  for (int i = a; i <= b; i++) {
    vector<int> check;
    int x = i;
    for (int j : prime) {
      while (x % j == 0) {
        check.push_back(j);
        x /= j;
      }
      if (x < 2)
        break;
    }
    if (isPrime(check.size()))
      ans++;
  }
  cout << ans;
  return 0;
}