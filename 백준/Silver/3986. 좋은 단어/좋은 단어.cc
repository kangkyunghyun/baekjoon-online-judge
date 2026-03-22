#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<char> v;
    for (char i : s) {
      if (v.empty()) {
        v.push_back(i);
      } else {
        if (v[v.size() - 1] == i)
          v.pop_back();
        else
          v.push_back(i);
      }
    }
    if (v.size() == 0)
      cnt++;
  }
  cout << cnt;
  return 0;
}