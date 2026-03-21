#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}

int main() {
  vector<pair<int, int>> v;
  for (int i = 0; i < 8; i++) {
    int x;
    cin >> x;
    v.push_back(make_pair(x, i + 1));
  }
  sort(v.begin(), v.end(), compare);
  int sum = 0;
  vector<int> ans;
  for (int i = 0; i < 5; i++) {
    sum += v[i].first;
    ans.push_back(v[i].second);
  }
  sort(ans.begin(), ans.end());
  cout << sum << '\n';
  for (int i : ans)
    cout << i << ' ';
  return 0;
}