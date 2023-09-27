#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int k;
  cin >> k;
  int cnt = 0;
  for (int i = 2; i * i <= k; i++) {
    while (k % i == 0) {
      k /= i;
      cnt++;
    }
  }
  if (k != 1)
    cnt++;
  if (log2(cnt) == (int)log2(cnt))
    cout << log2(cnt);
  else
    cout << (int)log2(cnt) + 1;
  return 0;
}