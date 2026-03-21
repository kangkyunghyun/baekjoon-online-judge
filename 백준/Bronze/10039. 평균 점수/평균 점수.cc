#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, ans = 0;
  for (int i = 0; i < 5; i++) {
    cin >> a;
    if (a >= 40)
      ans += a;
    else
      ans += 40;
  }
  cout << ans / 5 << '\n';
  return 0;
}