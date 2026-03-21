#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int d, p;
    cin >> d >> p;
    v.push_back({d, p});
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    int day = v[i].first;
    int point = v[i].second;
    pq.push(point);
    if (pq.size() > day)
      pq.pop();
  }
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}