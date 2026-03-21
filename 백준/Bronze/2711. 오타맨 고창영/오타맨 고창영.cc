#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s, ans = "";
    cin >> n >> s;
    for (int j = 0; j < s.size(); j++)
      if (j != n - 1)
        ans += s[j];
    cout << ans << '\n';
  }
  return 0;
}