#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  map<string, bool> listen;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    listen.insert(make_pair(s, true));
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (listen[s]) {
      cnt++;
      v.push_back(s);
    }
  }
  sort(v.begin(), v.end());
  cout << cnt << '\n';
  for (string elem : v)
    cout << elem << '\n';
  return 0;
}