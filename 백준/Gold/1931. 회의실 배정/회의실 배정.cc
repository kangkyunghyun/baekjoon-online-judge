#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    v.push_back({s, e});
  }
  sort(v.begin(), v.end(), cmp);
  int k = 0;
  for (int i = 0; i < n; i++)
    if (k <= v[i].first) {
      k = v[i].second;
      ans++;
    }
  cout << ans << '\n';
  return 0;
}