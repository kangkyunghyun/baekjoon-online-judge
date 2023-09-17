#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i])
      cnt += abs(a[i] - b[i]);
  }
  cout << cnt / 2;
}