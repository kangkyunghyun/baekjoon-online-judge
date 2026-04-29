#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int a = min(min(x1, y1), min(n - x1 + 1, n - y1 + 1));
    int b = min(min(x2, y2), min(n - x2 + 1, n - y2 + 1));
    cout << abs(a - b) << '
';
  }
  return 0;
}