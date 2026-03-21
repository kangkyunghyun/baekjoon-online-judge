#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> sieve(1000001, 1), prime;
  for (int i = 2; i <= 1000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 1000000; j += i)
        sieve[j] = 0;
    }
  while (1) {
    int n;
    cin >> n;
    if (!n)
      break;
    for (int i = 0; i < prime.size(); i++)
      if (sieve[n - prime[i]]) {
        cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
        break;
      }
  }
  return 0;
}