#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, cnt = 0;
  cin >> N >> M;
  vector<int> v(N + 2, 0);
  for (int i = 1; i <= N; i++) {
    cin >> v[i];
    if (v[i] && !v[i - 1])
      cnt++;
  }
  while (M--) {
    int a, b;
    cin >> a;
    if (!a) {
      cout << cnt << '\n';
    } else {
      cin >> b;
      if (v[b])
        continue;
      v[b] = 1;
      if (v[b - 1] && v[b + 1])
        cnt--;
      else if (!v[b - 1] && !v[b + 1])
        cnt++;
    }
  }
  return 0;
}