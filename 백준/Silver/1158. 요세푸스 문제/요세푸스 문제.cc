#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    q.push(i);
  cout << '<';
  int cnt = 0;
  while (q.size() > 1) {
    cnt++;
    if (cnt % k) {
      q.push(q.front());
      q.pop();
    } else {
      cout << q.front() << ", ";
      q.pop();
    }
  }
  cout << q.front() << ">\n";
  return 0;
}