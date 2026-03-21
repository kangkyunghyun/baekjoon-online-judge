#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x, y, ans = 0;
  cin >> n;
  map<int, int> mapX;
  map<int, int> mapY;
  while (n--) {
    cin >> x >> y;
    mapX[x]++;
    mapY[y]++;
  }
  for (auto i : mapX)
    if (i.second >= 2)
      ans++;
  for (auto i : mapY)
    if (i.second >= 2)
      ans++;
  cout << ans << '\n';
  return 0;
}