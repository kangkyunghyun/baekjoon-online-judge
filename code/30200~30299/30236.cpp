#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int x = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == x) {
        x++;
      }
      x++;
    }
    cout << x - 1 << '\n';
  }
  return 0;
}