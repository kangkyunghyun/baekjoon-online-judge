#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  double sum = 0;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      sum += 4;
      cnt++;
    } else if (s[i] == 'B') {
      sum += 3;
      cnt++;
    } else if (s[i] == 'C') {
      sum += 2;
      cnt++;
    } else if (s[i] == 'D') {
      sum += 1;
      cnt++;
    } else if (s[i] == 'F')
      cnt++;
    else if (s[i] == '+')
      sum += 0.5;
  }
  cout << sum / cnt;
  return 0;
}