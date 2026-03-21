#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int x, y;
  cin >> x >> y;
  if (x >= y)
    cout << x + (y / 10) + y;
  else
    cout << y + (x / 10) + x;
  return 0;
}