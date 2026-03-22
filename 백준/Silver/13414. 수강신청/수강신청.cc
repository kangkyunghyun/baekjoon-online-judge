#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k, l;
  cin >> k >> l;
  string s;
  map<string, int> m;
  for (int i = 0; i < l; i++) {
    cin >> s;
    m[s] = i + 1;
  }
  vector<pair<int, string>> v;
  for (auto i : m)
    v.push_back(make_pair(i.second, i.first));
  sort(v.begin(), v.end());
  for (int i = 0; i < min(k, (int)v.size()); i++)
    cout << v[i].second << '\n';
  return 0;
}