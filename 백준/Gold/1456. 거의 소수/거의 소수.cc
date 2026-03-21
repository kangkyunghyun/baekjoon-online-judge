#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> sieve(10000001, 1), prime;
  for (int i = 2; i <= 10000000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 10000000; j += i)
        sieve[j] = 0;
    }
  long long a, b, ans = 0;
  cin >> a >> b;
  for (int i : prime) {
    long long tmp = i;
    while (tmp <= b / i) {
      tmp *= i;
      if (tmp >= a)
        ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}