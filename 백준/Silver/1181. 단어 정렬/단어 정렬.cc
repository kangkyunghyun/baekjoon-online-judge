#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
  if (a.length() == b.length())
    return a < b;
  return a.length() < b.length();
}

int main() {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (find(v.begin(), v.end(), s) == v.end())
      v.push_back(s);
  }
  sort(v.begin(), v.end(), compare);
  for (string i : v)
    cout << i << '\n';
  return 0;
}