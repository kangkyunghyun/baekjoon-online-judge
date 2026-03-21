#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int j = 1; j <= t; j++) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v{x};
    for (int i = 1; i < n; i++) {
      cin >> x;
      if (v.back() < x)
        v.push_back(x);
      else
        *lower_bound(v.begin(), v.end(), x) = x;
    }
    cout << "Case #" << j;
    if (k > v.size())
      cout << "\n0\n";
    else
      cout << "\n1\n";
  }
  return 0;
}