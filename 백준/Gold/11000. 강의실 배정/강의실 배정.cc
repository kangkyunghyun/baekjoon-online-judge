#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    v[i] = make_pair(s, t);
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (pq.top() <= v[i].first)
      pq.pop();
  }
  cout << pq.size();
  return 0;
}