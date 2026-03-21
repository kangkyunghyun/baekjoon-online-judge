#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  vector<int> sieve(n + 1, 1), prime;
  for (int i = 2; i <= n; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= n; j += i)
        sieve[j] = 0;
    }
  for (int i = 0; i < prime.size(); i++) {
    int sum = 0;
    for (int j = i; j < prime.size(); j++) {
      sum += prime[j];
      if (sum == n)
        ans++;
      else if (sum > n)
        break;
    }
  }
  cout << ans;
  return 0;
}