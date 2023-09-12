#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, total = 0, skip = 0;
  cin >> n;
  vector<pii> v(n);
  cin >> v[0].first >> v[0].second;
  for (int i = 1; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    total += dist(v[i], v[i - 1]);
  }
  for (int i = 1; i < n - 1; i++) {
    int a = dist(v[i], v[i - 1]) + dist(v[i], v[i + 1]);
    int b = dist(v[i - 1], v[i + 1]);
    skip = max(skip, a - b);
  }
  cout << total - skip;
  return 0;
}