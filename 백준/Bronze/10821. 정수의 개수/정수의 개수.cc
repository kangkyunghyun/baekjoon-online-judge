#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int index = 0, comma = s.find(','), cnt = 0;
  while (comma != string::npos) {
    cnt++;
    index = comma + 1;
    comma = s.find(',', index);
  }
  cout << cnt + 1;
  return 0;
}