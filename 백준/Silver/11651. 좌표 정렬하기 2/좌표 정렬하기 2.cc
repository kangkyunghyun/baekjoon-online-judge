#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> v[i][1];
    cin >> v[i][0];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    cout << v[i][1] << ' ' << v[i][0] << '\n';
  return 0;
}