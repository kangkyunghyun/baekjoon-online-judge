#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (1) {
    cin >> n;
    if (!n)
      break;
    vector<int> sieve(2 * n + 1, 1);
    sieve[0] = 0, sieve[1] = 0;
    for (int i = 2; i * i <= 2 * n; i++)
      if (sieve[i])
        for (int j = i * 2; j <= 2 * n; j += i)
          sieve[j] = 0;
    int cnt = 0;
    for (int i = n + 1; i <= 2 * n; i++)
      if (sieve[i])
        cnt++;
    cout << cnt << '\n';
  }
  return 0;
}