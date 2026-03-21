#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s, bomb;
  cin >> s >> bomb;
  vector<char> v;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s[i]);
    if (v.back() == bomb[bomb.size() - 1]) {
      int cnt = 1;
      for (int j = bomb.size() - 2; j >= 0; j--)
        if (v[v.size() + j - bomb.size()] == bomb[j])
          cnt++;
      if (cnt == bomb.size())
        for (int j = 0; j < bomb.size(); j++)
          v.pop_back();
    }
  }
  if (v.empty())
    cout << "FRULA";
  else
    for (char i : v)
      cout << i;
  return 0;
}