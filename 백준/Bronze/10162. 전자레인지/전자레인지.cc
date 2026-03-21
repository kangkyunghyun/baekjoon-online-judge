#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t, a = 0, b = 0, c = 0;
  cin >> t;
  while (t >= 300) {
    a++;
    t -= 300;
  }
  while (t >= 60) {
    b++;
    t -= 60;
  }
  while (t >= 10) {
    c++;
    t -= 10;
  }
  if (t)
    cout << -1;
  else
    cout << a << ' ' << b << ' ' << c;
  return 0;
}