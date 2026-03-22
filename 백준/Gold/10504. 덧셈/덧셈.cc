#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, i = 2;
    cin >> n;
    int x = n / i;
    while (1) {
      if (x - (i / 2) < 0) {
        cout << "IMPOSSIBLE\n";
        break;
      }
      if (i % 2) {
        if (!(n % i)) {
          cout << n << " = ";
          for (int j = x - (i / 2); j < x + (i / 2); j++)
            cout << j << " + ";
          cout << x + (i / 2) << '\n';
          break;
        }
      } else {
        if (n % i == i / 2) {
          cout << n << " = ";
          for (int j = x - (i / 2) + 1; j < x + (i / 2); j++)
            cout << j << " + ";
          cout << x + (i / 2) << '\n';
          break;
        }
      }
      i++;
      x = n / i;
    }
  }
  return 0;
}