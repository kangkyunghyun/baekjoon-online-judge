#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, l, r;
  cin >> x >> l >> r;
  if (x <= l)
    cout << l;
  else if (x >= r)
    cout << r;
  else
    cout << x;
  return 0;
}