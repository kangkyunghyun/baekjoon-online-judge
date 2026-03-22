#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < n * n; i++) {
    cin >> x;
    if (pq.size() < n) {
      pq.push(x);
    } else if (pq.top() < x) {
      pq.pop();
      pq.push(x);
    } else {
      continue;
    }
  }
  cout << pq.top();
  return 0;
}