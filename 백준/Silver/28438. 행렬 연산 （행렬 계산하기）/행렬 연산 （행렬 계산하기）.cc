#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> row(n, 0), col(m, 0);
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      row[b - 1] += c;
    } else {
      col[b - 1] += c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << row[i] + col[j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}