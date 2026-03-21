#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int m = floor(0.15 * n + 0.5);
  cout << (n ? floor((double)accumulate(v.begin() + m, v.begin() + (n - m), 0) / (n - 2 * m) + 0.5) : 0);
  return 0;
}