#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  queue<int> q;
  while (1) {
    cin >> x;
    if (x == 0)
      q.pop();
    else if (x == -1)
      break;
    else if (q.size() >= n)
      continue;
    else
      q.push(x);
  }
  int size = q.size();
  for (int i = 0; i < size; i++) {
    cout << q.front() << ' ';
    q.pop();
  }
  return 0;
}