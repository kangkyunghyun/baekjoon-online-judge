#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, ans = 0;
  string s;
  cin >> n >> m >> s;
  for (int i = 1; i < s.length(); i++) {
    int cnt = 0;
    if (s[i - 1] == 'I')
      while (s[i] == 'O' && s[i + 1] == 'I') {
        cnt++;
        i += 2;
        if (cnt == n) {
          cnt--;
          ans++;
        }
      }
  }
  cout << ans << '\n';
  return 0;
}