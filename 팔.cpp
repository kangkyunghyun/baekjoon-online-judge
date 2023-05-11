#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string l, r;
  cin >> l >> r;
  if (l.size() != r.size()) {
    cout << 0;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < l.size(); i++)
    if (l[i] == r[i]) {
      if (l[i] == '8')
        cnt++;
    } else {
      break;
    }
  cout << cnt;
  return 0;
}