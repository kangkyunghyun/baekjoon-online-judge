#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a + b) % 2 != 0 || (a - b) % 2 != 0 || (a + b) / 2 < 0 || (a - b) / 2 < 0)
    cout << -1 << '\n';
  else
    cout << (a + b) / 2 << ' ' << (a - b) / 2 << '\n';
  return 0;
}