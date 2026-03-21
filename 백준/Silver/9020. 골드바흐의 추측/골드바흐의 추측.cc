#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  vector<int> prime(10001, 1);
  prime[0] = 0, prime[1] = 0;
  for (int i = 2; i < 10001; i++)
    if (prime[i])
      for (int j = i + i; j < 10001; j += i)
        prime[j] = 0;
  while (t--) {
    int n, a, b;
    cin >> n;
    for (int i = n / 2; i < n; i++)
      if (prime[n - i] && prime[i]) {
        a = n - i;
        b = i;
        break;
      }
    cout << a << ' ' << b << '\n';
  }
  return 0;
}