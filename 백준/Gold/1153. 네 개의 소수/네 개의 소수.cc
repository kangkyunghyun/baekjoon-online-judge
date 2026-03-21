#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  if (n < 8) {
    cout << -1;
    return 0;
  }
  vector<int> sieve(n + 1, 1), prime, ans;
  for (int i = 2; i * i <= n; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= n; j += i)
        sieve[j] = 0;
    }
  if (n % 2) {
    ans.push_back(2);
    ans.push_back(3);
    n -= 5;
  } else {
    ans.push_back(2);
    ans.push_back(2);
    n -= 4;
  }
  for (int i = 0; i < prime.size(); i++)
    if (sieve[n - prime[i]]) {
      ans.push_back(prime[i]);
      ans.push_back(n - prime[i]);
      break;
    }
  for (int i : ans)
    cout << i << ' ';
  return 0;
}