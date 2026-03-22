#include <bits/stdc++.h>
using namespace std;

int N, r, c, cnt = 0;

void z(int n, int x, int y) { // x = 0 , y = 4 , n = 4
  if (x == r && y == c)
    cout << cnt;
  else if (r >= x && r < x + n && c >= y && c < y + n) {
    z(n / 2, x, y);
    z(n / 2, x, y + n / 2);
    z(n / 2, x + n / 2, y);
    z(n / 2, x + n / 2, y + n / 2);
  } else
    cnt += n * n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> r >> c;
  z(1 << N, 0, 0);
  return 0;
}