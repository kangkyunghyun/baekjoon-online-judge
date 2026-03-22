#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> sieve(1000001, 1);
  for (int i = 2; i <= 1000000; i++)
    if (sieve[i])
      for (int j = i * 2; j <= 1000000; j += i)
        sieve[j] = 0;
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    int visited[1000001] = {0}, ans = -1;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      if (curr >= a && curr <= b && sieve[curr]) {
        ans = visited[curr] - 1;
        break;
      }
      if (!visited[curr / 2]) {
        q.push(curr / 2);
        visited[curr / 2] = visited[curr] + 1;
      }
      if (!visited[curr / 3]) {
        q.push(curr / 3);
        visited[curr / 3] = visited[curr] + 1;
      }
      if (!visited[curr + 1]) {
        q.push(curr + 1);
        visited[curr + 1] = visited[curr] + 1;
      }
      if (!visited[curr - 1] && curr - 1 >= 0) {
        q.push(curr - 1);
        visited[curr - 1] = visited[curr] + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}