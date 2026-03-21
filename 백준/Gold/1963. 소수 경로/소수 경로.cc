#include <bits/stdc++.h>
using namespace std;

int ans;
string a, b;
vector<int> sieve(10001, 1), visited(10001, 0);

void bfs() {
  ans = -1;
  queue<pair<string, int>> q;
  q.push({a, 1});
  visited[stoi(a)] = 1;
  while (!q.empty()) {
    string s = q.front().first;
    int cnt = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      char tmp = s[i];
      for (int j = 0; j < 10; j++) {
        s[i] = j + '0';
        int n = stoi(s);
        if (n >= 1000 && n <= 9999 && sieve[n] && !visited[n]) {
          if (s == b) {
            ans = cnt;
            return;
          }
          q.push({s, cnt + 1});
          visited[n] = 1;
        }
      }
      s[i] = tmp;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i <= 10000; i++)
    if (sieve[i])
      for (int j = i * 2; j <= 10000; j += i)
        sieve[j] = 0;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == b) {
      cout << "0\n";
      continue;
    }
    for (int i = 1000; i <= 9999; i++)
      visited[i] = 0;
    bfs();
    if (ans == -1)
      cout << "Impossible\n";
    else
      cout << ans << '\n';
  }
  return 0;
}