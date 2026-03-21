#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  while (1) {
    long long n, a, b;
    cin >> n;
    if (n == 0)
      break;
    cin >> a >> b;
    map<int, int> m;
    int next = 0, cnt = 1;
    m[next] = cnt;
    cnt++;
    while (1) {
      next = (((a * next) % n) * next % n + b) % n;
      if (m.find(next) != m.end())
        break;
      m[next] += cnt;
      cnt++;
    }
    cout << n - (cnt - m[next]) << '\n';
  }
  return 0;
}