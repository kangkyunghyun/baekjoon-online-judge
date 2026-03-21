#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  deque<int> dq;
  dq.push_back(n);
  for (int i = 0; i < n - 1; i++) {
    dq.push_front(n - 1 - i);
    for (int j = 0; j < n - 1 - i; j++) {
      dq.push_front(dq.back());
      dq.pop_back();
    }
  }
  for (int i : dq)
    cout << i << ' ';
  return 0;
}