#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  vector<string> v;
  for (int i = 0; i < s.size(); i++) {
    string ss = s.substr(i, s.size() - i);
    v.push_back(ss);
  }
  sort(v.begin(), v.end());
  for (string i : v)
    cout << i << '\n';
  return 0;
}