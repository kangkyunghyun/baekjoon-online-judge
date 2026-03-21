#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> s;
  int size = s.size();
  string ans(size, 'z');
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      string tmp = s;
      reverse(tmp.begin(), tmp.begin() + i + 1);
      reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
      reverse(tmp.begin() + j + 1, tmp.end());
      ans = min(ans, tmp);
    }
  }
  cout << ans;
  return 0;
}