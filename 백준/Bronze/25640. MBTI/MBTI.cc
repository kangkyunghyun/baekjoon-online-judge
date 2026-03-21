#include <bits/stdc++.h>
using namespace std;

int main() {
  string j, f;
  cin >> j;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    if (f == j)
      cnt++;
  }
  cout << cnt << '\n';
  return 0;
}