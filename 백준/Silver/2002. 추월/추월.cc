#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  map<string, int> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    m.insert(make_pair(s, i + 1));
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(m[s]);
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (v[i] > v[j]) {
        ans++;
        break;
      }
  cout << ans;
  return 0;
}