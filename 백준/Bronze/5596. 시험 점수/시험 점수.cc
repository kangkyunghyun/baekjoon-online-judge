#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, a = 0, b = 0;
  for (int i = 0; i < 4; i++) {
    cin >> t;
    a += t;
  }
  for (int i = 0; i < 4; i++) {
    cin >> t;
    b += t;
  }
  if (a >= b)
    cout << a;
  else
    cout << b;
  return 0;
}