#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  int *arr = new int[n + 1];
  for (int i = 2; i <= n; i++)
    arr[i] = 1;
  for (int i = 2; i * i <= n; i++) {
    if (arr[i] == 0)
      continue;
    for (int j = i * i; j <= n; j += i)
      arr[j] = 0;
  }
  for (int i = m; i <= n; i++)
    if (arr[i] != 0)
      cout << i << '\n';
  return 0;
}