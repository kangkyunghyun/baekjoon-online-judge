#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, cnt = 0, x;
  cin >> n >> m;
  map<int, bool> A, B;
  for (int i = 0; i < n; i++) {
    cin >> x;
    A.insert(make_pair(x, true));
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    B.insert(make_pair(x, true));
  }
  for (auto i = B.begin(); i != B.end(); i++)
    if (!A[i->first])
      cnt++;
  for (auto i = A.begin(); i != A.end(); i++)
    if (!B[i->first])
      cnt++;
  cout << cnt << '\n';
  return 0;
}