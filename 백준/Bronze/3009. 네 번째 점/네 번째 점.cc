#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  int x[1001] = {0};
  int y[1001] = {0};
  for (int i = 0; i < 3; i++) {
    cin >> a >> b;
    x[a]++;
    y[b]++;
  }
  for (int i = 0; i < 1001; i++)
    if (x[i] == 1) {
      cout << i << ' ';
      break;
    }
  for (int i = 0; i < 1001; i++)
    if (y[i] == 1) {
      cout << i;
      break;
    }
  return 0;
}