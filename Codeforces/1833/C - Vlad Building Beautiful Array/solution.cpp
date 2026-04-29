#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, o = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2)
        o++;
    }
    int m = *min_element(a.begin(), a.end());
    if (o >= 1) {
      if (m % 2) {
        cout << "YES
";
      } else {
        cout << "NO
";
      }
    } else {
      cout << "YES
";
    }
  }
  return 0;
}