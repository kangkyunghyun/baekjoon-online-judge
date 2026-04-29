#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  char a[] = {'v', 'i', 'k', 'a'};
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cin >> v[i];
    for (int c = 0; c < m; c++) {
      for (int r = 0; r < n; r++) {
        if (v[r][c] == a[cnt]) {
          cnt++;
          break;
        }
      }
    }
    if (cnt == 4)
      cout << "YES
";
    else
      cout << "NO
";
  }
  return 0;
}