#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = n - i - 1; j > 0; j--)
      cout << ' ';
    if (i == 0)
      cout << '*';
    else if (i == n - 1) {
      for (int j = 0; j < 2 * n - 1; j++)
        cout << '*';
    } else {
      cout << '*';
      for (int j = 0; j < 2 * i - 1; j++)
        cout << ' ';
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}