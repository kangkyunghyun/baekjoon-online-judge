#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c = 1;
    cin >> a >> b;
    for (int j = 0; j < b; j++)
      c = (c * a) % 10;
    if (c)
      cout << c % 10 << '\n';
    else
      cout << 10 << '\n';
  }
  return 0;
}