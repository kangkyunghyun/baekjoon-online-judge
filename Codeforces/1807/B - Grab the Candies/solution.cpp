#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, a = 0, b = 0;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
        a += x;
      } else {
        b += x;
      }
    }
    if (a > b)
      cout << "YES
";
    else
      cout << "NO
";
  }
  return 0;
}