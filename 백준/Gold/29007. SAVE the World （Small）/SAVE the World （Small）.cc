#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    string cmd = "";
    while (1) {
      if (!x && !y)
        break;
      if (x > 0 && y > 0) { // 1사분면
        if (y >= x) {
          cmd += 'A';
          x--;
        } else {
          cmd += 'W';
          y++;
        }
      } else if (x < 0 && y > 0) { // 2사분면
        if (y <= -x + 1) {
          cmd += 'X';
          y--;
        } else {
          cmd += 'A';
          x--;
        }
      } else if (x < 0 && y < 0) { // 3사분면
        if (y <= x) {
          cmd += 'D';
          x++;
        } else {
          cmd += 'X';
          y--;
        }
      } else if (x > 0 && y < 0) { // 4사분면
        if (y >= -x) {
          cmd += 'W';
          y++;
        } else {
          cmd += 'D';
          x++;
        }
      } else if (x == 0 && y > 0) { // y축 위
        if (y == 1) {
          cmd += 'X';
          y--;
        } else {
          cmd += 'A';
          x--;
        }
      } else if (x == 0 && y < 0) { // y축 아래
        cmd += 'D';
        x++;
      } else if (y == 0 && x > 0) { // x축 오른쪽
        cmd += 'W';
        y++;
      } else if (y == 0 && x < 0) { // x축 왼쪽
        cmd += 'X';
        y--;
      }
    }
    cout << cmd << '\n';
  }
  return 0;
}
/*
X X A A A A A A A A A A A A A A A A A A A A A A A A A A A A A
X X X A A A A A A A A A A A A A A A A A A A A A A A A A A A W
X X X X A A A A A A A A A A A A A A A A A A A A A A A A A W W
X X X X X A A A A A A A A A A A A A A A A A A A A A A A W W W
X X X X X X A A A A A A A A A A A A A A A A A A A A A W W W W
X X X X X X X A A A A A A A A A A A A A A A A A A A W W W W W
X X X X X X X X A A A A A A A A A A A A A A A A A W W W W W W
X X X X X X X X X A A A A A A A A A A A A A A A W W W W W W W
X X X X X X X X X X A A A A A A A A A A A A A W W W W W W W W
X X X X X X X X X X X A A A A A A A A A A A W W W W W W W W W
X X X X X X X X X X X X A A A A A A A A A W W W W W W W W W W
X X X X X X X X X X X X X A A A A A A A W W W W W W W W W W W
X X X X X X X X X X X X X X A A A A A W W W W W W W W W W W W
X X X X X X X X X X X X X X X A A A W W W W W W W W W W W W W
X X X X X X X X X X X X X X X X A W W W W W W W W W W W W W W
X X X X X X X X X X X X X X X 0 W W W W W W W W W W W W W W W
X X X X X X X X X X X X X X D D W W W W W W W W W W W W W W W
X X X X X X X X X X X X X D D D D W W W W W W W W W W W W W W
X X X X X X X X X X X X D D D D D D W W W W W W W W W W W W W
X X X X X X X X X X X D D D D D D D D W W W W W W W W W W W W
X X X X X X X X X X D D D D D D D D D D W W W W W W W W W W W
X X X X X X X X X D D D D D D D D D D D D W W W W W W W W W W
X X X X X X X X D D D D D D D D D D D D D D W W W W W W W W W
X X X X X X X D D D D D D D D D D D D D D D D W W W W W W W W
X X X X X X D D D D D D D D D D D D D D D D D D W W W W W W W
X X X X X D D D D D D D D D D D D D D D D D D D D W W W W W W
X X X X D D D D D D D D D D D D D D D D D D D D D D W W W W W
X X X D D D D D D D D D D D D D D D D D D D D D D D D W W W W
X X D D D D D D D D D D D D D D D D D D D D D D D D D D W W W
X D D D D D D D D D D D D D D D D D D D D D D D D D D D D W W
D D D D D D D D D D D D D D D D D D D D D D D D D D D D D D W
*/