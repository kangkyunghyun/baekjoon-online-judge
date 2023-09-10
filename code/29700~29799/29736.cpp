#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, k, x;
  cin >> a >> b >> k >> x;
  int cnt = 0;
  for (int i = k - x; i <= k + x; i++)
    if (i >= a && i <= b)
      cnt++;
  if (cnt)
    cout << cnt;
  else
    cout << "IMPOSSIBLE";
  return 0;
}