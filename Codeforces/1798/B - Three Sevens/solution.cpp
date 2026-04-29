#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, flag = 0;
    cin >> m;
    map<int, int> M;
    for (int i = 1; i <= m; i++) {
      int n;
      cin >> n;
      while (n--) {
        int x;
        cin >> x;
        M[x] = i;
      }
    }
    vector<int> ans(m + 1, -1);
    for (auto [n, day] : M)
      if (ans[day] == -1)
        ans[day] = n;
    for (int i = 1; i <= m; i++)
      if (ans[i] == -1) {
        flag = 1;
        break;
      }
    if (flag)
      cout << -1;
    else
      for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    cout << '
';
  }
  return 0;
}