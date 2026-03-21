#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, p, a;
  cin >> l >> p;
  for (int i = 0; i < 5; i++) {
    cin >> a;
    cout << a - l * p << ' ';
  }
  return 0;
}