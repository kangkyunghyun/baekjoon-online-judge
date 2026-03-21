#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, now = 0, cnt = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cnt++;
    now += x;
    if (now >= n)
      break;
    now += v[now];
    if (now >= n)
      break;
  }
  cout << cnt;
  return 0;
}