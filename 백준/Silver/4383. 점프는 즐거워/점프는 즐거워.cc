#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    int ans = 0;
    vector<int> v(n), check(n, 0);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
      int tmp = abs(v[i] - v[i + 1]);
      if (tmp >= 1 && tmp <= n - 1)
        check[tmp] = 1;
    }
    for (int i = 1; i < n; i++)
      if (check[i])
        ans++;
    if (ans == n - 1)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }
  return 0;
}