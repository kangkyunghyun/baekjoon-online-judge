#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, a;
  cin >> q;
  while (q--) {
    cin >> a;
    cout << (log2(a) == (int)log2(a)) << '\n';
  }
  return 0;
}