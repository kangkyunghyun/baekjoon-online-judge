#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << "YES\n";
  if (n % 2) {
    for (int i = n - 1; i > 1; i -= 2)
      cout << i << ' ';
    cout << n << ' ';
    for (int i = 1; i < n; i += 2)
      cout << i << ' ';
    cout << '\n';
  } else {
    for (int i = n - 1; i > 0; i -= 2)
      cout << i << ' ';
    cout << n << ' ';
    for (int i = 2; i < n; i += 2)
      cout << i << ' ';
    cout << '\n';
  }
  int odd = 1, even = n;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      cout << odd << ' ';
      odd++;
    } else {
      cout << even << ' ';
      even--;
    }
  }
  return 0;
}