#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr[5][5], bingo = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> arr[i][j];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      int flag = 0;
      int n, m;
      for (int a = 0; !flag && a < 5; a++)
        for (int b = 0; !flag && b < 5; b++)
          if (arr[a][b] == x) {
            arr[a][b] = 0;
            n = a;
            m = b;
            flag = 1;
          }
      int cnt = 0;
      for (int a = 0; a < 5; a++)
        if (arr[n][a] == 0)
          cnt++;
      if (cnt == 5)
        bingo++;
      cnt = 0;
      for (int a = 0; a < 5; a++)
        if (arr[a][m] == 0)
          cnt++;
      if (cnt == 5)
        bingo++;
      cnt = 0;
      if ((n == 0 && m == 0) || (n == 1 && m == 1) || (n == 2 && m == 2) || (n == 3 && m == 3) || (n == 4 && m == 4)) {
        for (int a = 0; a < 5; a++)
          if (arr[a][a] == 0)
            cnt++;
        if (cnt == 5)
          bingo++;
      }
      cnt = 0;
      if ((n == 0 && m == 4) || (n == 1 && m == 3) || (n == 2 && m == 2) || (n == 3 && m == 1) || (n == 4 && m == 0)) {
        for (int a = 0; a < 5; a++)
          if (arr[a][4 - a] == 0)
            cnt++;
        if (cnt == 5)
          bingo++;
      }
      if (bingo >= 3) {
        cout << i *5+ j + 1;
        return 0;
      }
    }
  }
  return 0;
}