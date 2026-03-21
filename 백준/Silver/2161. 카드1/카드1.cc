#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++)
    q.push(i + 1);
  while (q.size() != 0) {
    cout << q.front() << ' ';
    q.pop();
    q.push(q.front());
    q.pop();
  }
  return 0;
}