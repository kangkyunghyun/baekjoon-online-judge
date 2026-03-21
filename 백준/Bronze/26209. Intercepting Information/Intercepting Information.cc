#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b = 0, i = 9;
  while (i--) {
    cin >> a;
    if (a == 9)
      b = 1;
  }
  cout << (b ? 'F' : 'S');
  return 0;
}