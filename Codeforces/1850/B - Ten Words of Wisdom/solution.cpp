#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, t = 0, idx = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if (a <= 10 && b > t) {
        t = b;
        idx = i + 1;
      }
    }
    cout << idx << '
';
  }
  return 0;
}