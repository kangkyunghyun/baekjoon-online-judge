#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  while (n--) {
    int a;
    char b;
    cin >> b >> b >> a;
    if (a <= 90)
      ans++;
  }
  cout << ans;
  return 0;
}