#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a = 1, b = 2 * n * m - n - m + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        cout << a << ' ';
        a++;
      } else {
        cout << b << ' ';
        b--;
      }
    }
    a += m / 2;
    b -= m / 2;
    if (m % 2 == 0) {
      if (i % 2 == 0)
        b += 1;
      else
        a -= 1;
    }
    cout << '\n';
  }
  return 0;
}