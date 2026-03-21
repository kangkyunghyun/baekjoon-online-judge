#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int ans = 0;
  string s;
  cin >> s;
  while (s.size() != 1) {
    int tmp = 1;
    for (int i = 0; i < s.size(); i++)
      tmp *= s[i] - '0';
    s = to_string(tmp);
    ans++;
  }
  cout << ans;
  return 0;
}