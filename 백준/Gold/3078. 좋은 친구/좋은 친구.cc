#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, ans = 0;
  cin >> n >> k;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  queue<int> q[21];
  for (int i = 0; i < n; i++) {
    int len = v[i].size();
    while (!q[len].empty() && i - q[len].front() > k)
      q[len].pop();
    ans += q[len].size();
    q[len].push(i);
  }
  cout << ans;
  return 0;
}