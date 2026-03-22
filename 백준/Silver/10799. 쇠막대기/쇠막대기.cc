#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  stack<char> S;
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '(') {
      S.push(s[i]);
    } else if (s[i] == ')' && s[i - 1] == '(') {
      S.pop();
      ans += S.size();
    } else {
      S.pop();
      ans++;
    }
  cout << ans;
  return 0;
}