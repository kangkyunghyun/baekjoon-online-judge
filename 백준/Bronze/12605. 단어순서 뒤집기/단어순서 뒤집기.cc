#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    vector<string> v;
    string s;
    getline(cin, s);
    s += ' ';
    int space = s.find(' '), index = 0;
    while (space != string::npos) {
      string ss = s.substr(index, space - index);
      v.push_back(ss);
      index = space + 1;
      space = s.find(' ', index);
    }
    cout << "Case #" << i + 1 << ": ";
    for (int i = v.size() - 1; i >= 0; i--)
      cout << v[i] << ' ';
    cout << '\n';
  }
  return 0;
}