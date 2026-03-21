#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> v[i][0];
    cin >> v[i][1];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    cout << v[i][0] << ' ' << v[i][1] << '\n';
  return 0;
}