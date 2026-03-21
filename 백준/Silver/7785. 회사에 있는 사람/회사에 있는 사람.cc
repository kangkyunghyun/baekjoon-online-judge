#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  map<string, bool> m;
  for (int i = 0; i < n; i++) {
    string name, check;
    cin >> name >> check;
    if (check == "enter")
      m[name] = true;
    else if (check == "leave")
      m[name] = false;
  }
  vector<string> v;
  for (auto i : m)
    if (i.second)
      v.push_back(i.first);
  for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << '\n';
  return 0;
}