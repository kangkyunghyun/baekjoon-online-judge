#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, q, p = 0;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int i, t;
      cin >> i >> t;
      v[(i + p - 1) % n] += t;
    } else if (x == 2) {
      int t;
      cin >> t;
      p = (p + n - t) % n;
    } else {
      int t;
      cin >> t;
      p = (p + t) % n;
    }
  }
  if (p) {
    for (int i = p; i < n; i++)
      cout << v[i] << ' ';
    for (int i = 0; i < p; i++)
      cout << v[i] << ' ';
  } else {
    for (int i = 0; i < n; i++)
      cout << v[i] << ' ';
  }
  return 0;
}