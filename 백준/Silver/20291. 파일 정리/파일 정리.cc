#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  map<string, int> m;
  while (n--) {
    string s;
    cin >> s;
    int i = s.find('.');
    string t = s.substr(i + 1, s.size() - i - 1);
    if (m.find(t) != m.end())
      m[t]++;
    else
      m.insert({t, 1});
  }
  for (auto i : m)
    cout << i.first << ' ' << i.second << '\n';
  return 0;
}
