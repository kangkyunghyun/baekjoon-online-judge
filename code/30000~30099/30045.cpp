#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  int cnt = 0;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s.find("01") != string::npos || s.find("OI") != string::npos)
      cnt++;
  }
  cout << cnt;
  return 0;
}