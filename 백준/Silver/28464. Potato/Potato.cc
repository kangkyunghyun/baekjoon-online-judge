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
  cout << accumulate(v.begin(), v.begin() + n / 2, 0) << ' ' << accumulate(v.begin() + n / 2, v.end(), 0);
  return 0;
}