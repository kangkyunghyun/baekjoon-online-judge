#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x = 0, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> y;
    x += y;
  }
  cout << "Junhee is " << (x < n - x ? "not " : "") << "cute!";
  return 0;
}
