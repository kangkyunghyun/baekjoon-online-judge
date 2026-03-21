#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  while (1) {
    int n, m, ans = 0, start = 0, end = 0;
    cin >> n >> m;
    if (!n && !m)
      break;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    while (1) {
      if (start == a.size() || end == b.size())
        break;
      else if (a[start] < b[end])
        start++;
      else if (a[start] > b[end])
        end++;
      else {
        start++;
        end++;
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}