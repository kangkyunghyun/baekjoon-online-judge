#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  vector<int> bag(k);
  for (int i = 0; i < k; i++)
    cin >> bag[i];
  sort(v.begin(), v.end());
  sort(bag.begin(), bag.end());
  priority_queue<int> pq;
  int idx = 0;
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    while (idx < n && v[idx].first <= bag[i]) {
      pq.push(v[idx].second);
      idx++;
    }
    if (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }
  cout << sum;
  return 0;
}