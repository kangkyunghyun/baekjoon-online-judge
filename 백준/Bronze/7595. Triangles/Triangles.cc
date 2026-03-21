#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (!n)
      break;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++)
        cout << '*';
      cout << '\n';
    }
  }
  return 0;
}