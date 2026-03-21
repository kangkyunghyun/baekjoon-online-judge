#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 1000000; j += i)
        sieve[j] = 0;
    }
  int t, n;
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < prime.size(); i++) {
      if (n - prime[i] < prime[i])
        break;
      if (sieve[n - prime[i]])
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}