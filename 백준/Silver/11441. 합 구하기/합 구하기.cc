#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  cin >> m;
  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << v[j] - v[i - 1] << '\n';
  }
  return 0;
}