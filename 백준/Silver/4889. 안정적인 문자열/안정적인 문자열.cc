#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (1) {
    string s;
    cin >> s;
    if (s[0] == '-')
      break;
    vector<char> v;
    for (char i : s)
      if (i == '{')
        v.push_back(i);
      else if (!v.empty() && v.back() == '{')
        v.pop_back();
      else
        v.push_back(i);
    int ans = 0;
    if (!v.empty())
      for (int i = 0; i < v.size() - 1; i += 2) {
        if (v[i] == v[i + 1])
          ans++;
        else
          ans += 2;
      }
    cout << t++ << ". " << ans << '\n';
  }
  return 0;
}