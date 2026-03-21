#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, v, e;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> v >> e;
    cout << 2 - v + e << '\n';
  }
  return 0;
}