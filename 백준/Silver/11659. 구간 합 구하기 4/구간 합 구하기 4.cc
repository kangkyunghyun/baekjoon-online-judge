#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, sum = 0;
  cin >> n >> m;
  vector<int> v(n + 1, 0);
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    sum += x;
    v[i] = sum;
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << v[j] - v[i - 1] << '\n';
  }
  return 0;
}