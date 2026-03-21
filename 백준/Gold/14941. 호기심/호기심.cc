#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> sieve(500001, 1), prime;
  for (int i = 2; i <= 500000; i++)
    if (sieve[i]) {
      prime.push_back(i);
      for (int j = i * 2; j <= 500000; j += i)
        sieve[j] = 0;
    }
  while (n--) {
    int a, b, cnt = 1, ans = 0;
    cin >> a >> b;
    auto s = lower_bound(prime.begin(), prime.end(), a);
    auto e = upper_bound(prime.begin(), prime.end(), b);
    for (auto it = s; it != e; it++, cnt++)
      if (cnt % 2)
        ans += 3 * *it;
      else
        ans -= *it;
    cout << ans << '\n';
  }
  return 0;
}