#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x % 2)
        odd++;
    }
    if (odd % 2 == 0)
      cout << "YES";
    else
      cout << "NO";
    cout << '
';
  }
  return 0;
}