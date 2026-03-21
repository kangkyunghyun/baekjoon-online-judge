#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cnt++;
    if (to_string(i).find("50") != -1)
      cnt++;
  }
  if (to_string(n).find("50") != -1)
    cout << cnt - 1;
  else
    cout << cnt;
  return 0;
}
