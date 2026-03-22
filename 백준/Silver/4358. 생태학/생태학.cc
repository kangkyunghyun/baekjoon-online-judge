#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  map<string, int> m;
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    cnt++;
    if (m.find(s) == m.end())
      m[s] = 1;
    else
      m[s]++;
  }
  cout.precision(4);
  cout << fixed;
  for (auto i : m)
    cout << i.first << ' ' << (float)i.second / cnt * 100 << '\n';
  return 0;
}