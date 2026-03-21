#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int ans = 0, arr[26] = {0};
    cin >> s;
    for (char i : s)
      arr[i - 65]++;
    for (int i = 0; i < 26; i++)
      if (!arr[i])
        ans += i + 65;
    cout << ans << '\n';
  }
  return 0;
}