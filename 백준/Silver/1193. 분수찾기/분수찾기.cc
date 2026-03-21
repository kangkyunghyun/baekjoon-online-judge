#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, line = 1;
  cin >> x;
  while (x > line) {
    x -= line;
    line++;
  }
  if (line % 2)
    cout << line - x + 1 << '/' << x << '\n';
  else
    cout << x << '/' << line - x + 1 << '\n';
  return 0;
}