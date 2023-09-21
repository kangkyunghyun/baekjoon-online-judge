#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m = INT_MAX, M = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
  return 0;
}