#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < m; j++) {
      if (v[j] == x)
        cnt++;
    }
  }
  cout << m - cnt;
  return 0;
}