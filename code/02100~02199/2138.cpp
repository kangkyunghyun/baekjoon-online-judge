#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MAX;
string a, b;

void f(int x) {
  string tmp = a;
  int cnt = 0;
  if (x == 0) {
    tmp[0] = tmp[0] == '0' ? '1' : '0';
    tmp[1] = tmp[1] == '0' ? '1' : '0';
    cnt++;
  }
  for (int i = 1; i < n; i++) {
    if (tmp[i - 1] != b[i - 1]) {
      if (i - 1 >= 0)
        tmp[i - 1] = tmp[i - 1] == '0' ? '1' : '0';
      tmp[i] = tmp[i] == '0' ? '1' : '0';
      if (i + 1 < n)
        tmp[i + 1] = tmp[i + 1] == '0' ? '1' : '0';
      cnt++;
    }
  }
  if (tmp == b)
    ans = min(ans, cnt);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> a >> b;
  f(0), f(1);
  cout << (ans == INT_MAX ? -1 : ans);
  return 0;
}