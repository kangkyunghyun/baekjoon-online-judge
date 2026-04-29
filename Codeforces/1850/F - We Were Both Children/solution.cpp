#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (x <= n)
        a[x]++;
    }
    vector<int> sieve(n + 1, 0);
    for (int i = 1; i <= n; i++)
      if (a[i])
        for (int x = i; x <= n; x += i)
          sieve[x] += a[i];
    cout << *max_element(sieve.begin(), sieve.end()) << '
';
  }
  return 0;
}