#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a[101];
  fill(a, a + 101, "####################################################################################################");
  int x = 50, y = 50;
  int x1 = x, y1 = y, x2 = x, y2 = y;
  int n;
  string s;
  cin >> n >> s;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  int d = 0;
  a[x][y] = '.';
  for (char c : s) {
    if (c == 'L') {
      d = (d + 1) % 4;
    } else if (c == 'R') {
      d = (d + 3) % 4;
    } else {
      x += dx[d];
      y += dy[d];
      x1 = min(x1, x);
      y1 = min(y1, y);
      x2 = max(x2, x);
      y2 = max(y2, y);
      a[x][y] = '.';
    }
  }
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++)
      cout << a[i][j];
    cout << '\n';
  }
  return 0;
}