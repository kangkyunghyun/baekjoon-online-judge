#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++) {
      if (a[i] > a[n - 1]) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
      }
    }
    if (a[n - 1] == *max_element(a.begin(), a.end()) && b[n - 1] == *max_element(b.begin(), b.end())) {
      cout << "YES
";
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (b[i] > b[n - 1]) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
      }
    }
    if (a[n - 1] == *max_element(a.begin(), a.end()) && b[n - 1] == *max_element(b.begin(), b.end())) {
      cout << "YES
";
    } else {
      cout << "NO
";
    }
  }
  return 0;
}