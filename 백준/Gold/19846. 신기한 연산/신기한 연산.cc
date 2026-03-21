#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++)
    cout << char(97 + i % (2 * n) / 2);
  return 0;
}