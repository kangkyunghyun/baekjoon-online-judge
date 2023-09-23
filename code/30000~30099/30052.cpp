#include <bits/stdc++.h>
using namespace std;

int n, m, d;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> d;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d > max(max(i + j, abs(n - 1 - i) + abs(m - 1 - j)), max(abs(n - 1 - i) + j, abs(m - 1 - j) + i)))
        cnt++;
    }
  }
  cout << cnt;
  return 0;
}