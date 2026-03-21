#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, x;
  cin >> n >> l;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pq.push({-x, i});
    while (pq.top().second <= i - l)
      pq.pop();
    cout << -pq.top().first << ' ';
  }
  return 0;
}