#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> s;
  for (int i = 97; i <= 122; i++) {
    int cnt = 0;
    for (char j : s)
      if (j == (char)i)
        cnt++;
    cout << cnt << ' ';
  }
  return 0;
}
