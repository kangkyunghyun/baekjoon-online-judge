#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> sieve(1000001, 0);
  for (int i = 1; i <= 1000000; i++)
    for (int j = i * 2; j <= 1000000; j += i)
      sieve[j] += i;
  int cnt = 1;
  while (1) {
    int s, e, bad, ans = 0;
    cin >> s >> e >> bad;
    if (s == 0)
      break;
    for (int i = s; i <= e; i++) {
      if (abs(sieve[i] - i) <= bad)
        ans++;
    }
    cout << "Test " << cnt << ": " << ans << '\n';
    cnt++;
  }
  return 0;
}