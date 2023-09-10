#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[31] = {0, 1, 0, 1};
  int b[31] = {0, 0, 1, 1};
  for (int i = 4; i <= 30; i++) {
    a[i] = a[i - 1] + a[i - 2];
    b[i] = b[i - 1] + b[i - 2];
  }
  int d, k;
  scanf("%d %d", &d, &k);
  for (int i = 1; i <= k; i++)
    if ((k - a[d] * i) % b[d] == 0) {
      printf("%d\n%d", i, (k - a[d] * i) / b[d]);
      break;
    }
  return 0;
}