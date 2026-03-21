#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v{1, 1, 1, 2, 2};
    for (int i = 0, j = 4; v.size() < n; i++, j++)
      v.push_back(v[i] + v[j]);
    cout << v[n - 1] << '\n';
  }
  return 0;
}