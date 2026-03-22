#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, c, q, r1, c1, r2, c2;
  cin >> r >> c >> q;
  int arr[1001][1001] = {0};
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++) {
      cin >> arr[i][j];
      arr[i][j] += arr[i][j - 1];
    }
  while (q--) {
    int sum = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = r1; i <= r2; i++)
      sum += arr[i][c2] - arr[i][c1 - 1];
    cout << sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
  }
  return 0;
}