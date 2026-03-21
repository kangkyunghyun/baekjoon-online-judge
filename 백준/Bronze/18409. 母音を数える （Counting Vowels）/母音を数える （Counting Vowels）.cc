#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  string s, a = "aeiou";
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (a.find(s[i]) != -1)
      ans++;
  cout << ans;
  return 0;
}