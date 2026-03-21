#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
  return a.first < b.first;
}

int main() {
  int n;
  cin >> n;
  pair<int, string> usr;
  vector<pair<int, string>> v;
  for (int i = 0; i < n; i++) {
    cin >> usr.first >> usr.second;
    v.push_back(usr);
  }
  stable_sort(v.begin(), v.end(), compare);
  for (pair i : v)
    cout << i.first << ' ' << i.second << '\n';
  return 0;
}