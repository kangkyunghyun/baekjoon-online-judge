#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  cout << v[n - k] << '\n';
  return 0;
}