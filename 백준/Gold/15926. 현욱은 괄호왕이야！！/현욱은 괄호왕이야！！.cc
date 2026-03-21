#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  string str;
  stack<pair<char, int>> s;
  cin >> n >> str;
  for (int i = 0; i < n; i++)
    if (s.empty())
      s.push({str[i], i});
    else if (str[i] == ')' && s.top().first == '(')
      s.pop();
    else
      s.push({str[i], i});
  int a = n;
  while (!s.empty()) {
    int b = s.top().second;
    s.pop();
    ans = max(ans, a - b - 1);
    a = b;
  }
  ans = max(ans, a);
  cout << ans;
  return 0;
}