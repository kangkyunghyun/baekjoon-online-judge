#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  int h = 8 * (n - 1);
  while (n--) {
    cin >> x;
    h += x;
  }
  cout << h / 24 << ' ' << h % 24;
  return 0;
}
