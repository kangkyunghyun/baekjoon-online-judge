#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> v{x};
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (v.back() < x)
      v.push_back(x);
    else
      *lower_bound(v.begin(), v.end(), x) = x;
  }
  cout << v.size() << '\n';
  return 0;
}