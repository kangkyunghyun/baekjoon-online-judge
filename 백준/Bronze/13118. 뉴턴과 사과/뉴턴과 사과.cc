#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v(4);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  int x, y, r, ans = -1;
  cin >> x >> y >> r;
  for (int i = 0; i < 4; i++)
    if (v[i] == x)
      ans = i;
  cout << ans + 1;
  return 0;
}