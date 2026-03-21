#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  if (k < n + m - 1) {
    cout << "NO\n";
    return 0;
  }
  int arr[1001][1001];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      arr[i][j] = i + j + 1;
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << arr[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}