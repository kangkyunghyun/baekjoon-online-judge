#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++)
      cin >> a[i];
    int left = 0, right = n - 1;
    b[0] = a[0];
    b[n - 1] = a[n - 2];
    for (int i = 0; i < n - 2; i++) {
      if (a[i] < a[i + 1]) {
        b[i + 1] = a[i];
      } else {
        b[i + 1] = a[i + 1];
      }
    }
    for (int i : b)
      cout << i << ' ';
    cout << '
';
  }
  return 0;
}