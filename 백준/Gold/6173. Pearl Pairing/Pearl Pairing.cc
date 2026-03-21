#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  priority_queue<pii> pq;
  for (int i = 0; i < c; i++) {
    int x;
    cin >> x;
    pq.push({x, i + 1});
  }
  for (int i = 0; i < n / 2; i++) {
    pii a = pq.top();
    pq.pop();
    pii b = pq.top();
    pq.pop();
    cout << a.second << ' ' << b.second << '\n';
    a.first--;
    b.first--;
    if (a.first)
      pq.push(a);
    if (b.first)
      pq.push(b);
  }
  return 0;
}