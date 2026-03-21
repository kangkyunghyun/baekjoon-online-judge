#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> v;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_pair(make_pair(a, b), c));
    m.insert(make_pair(a, 0));
  }
  sort(v.begin(), v.end(), compare);
  vector<pair<int, int>> ans;
  for (int i = 0; ans.size() < 3; i++)
    if (m[v[i].first.first] < 2) {
      ans.push_back(v[i].first);
      m[v[i].first.first]++;
    }
  for (auto i : ans)
    cout << i.first << ' ' << i.second << '\n';
  return 0;
}