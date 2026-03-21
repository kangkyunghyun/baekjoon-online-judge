#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> v(n);
  vector<char> ans;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < v[0].size(); i++) {
    int err = 0;
    string s = v[0];
    for (int j = 0; j < n; j++)
      if (s[i] != v[j][i])
        err++;
    if (err)
      ans.push_back('?');
    else
      ans.push_back(s[i]);
  }
  for (char c : ans)
    cout << c;
  return 0;
}