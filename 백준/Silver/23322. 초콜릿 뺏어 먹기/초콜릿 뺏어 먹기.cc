#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, a = 0, b = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++)
    if (v[i] > v[0]) {
      a += v[i] - v[0];
      b++;
    }
  cout << a << ' ' << b;
  return 0;
}