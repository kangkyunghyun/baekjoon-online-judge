#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  int arr[32][32];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];
  for (int k = 0; k < 2; k++)
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++)
        if (arr[i][j] == x)
          cnt++;
      if (cnt > n / 2)
        for (int j = 1; j <= n; j++)
          arr[i][j] = x;
      cnt = 0;
      for (int j = 1; j <= n; j++)
        if (arr[j][i] == x)
          cnt++;
      if (cnt > n / 2)
        for (int j = 1; j <= n; j++)
          arr[j][i] = x;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (arr[i][j] != x) {
        cout << 0;
        return 0;
      }
  cout << 1;
  return 0;
}