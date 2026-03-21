#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  int isL = 0, isS = 0;
  for (char i : s) {
    if (i >= 49 && i <= 57) {
      cnt++;
    } else if (i == 'L') {
      isL++;
    } else if (i == 'S') {
      isS++;
    } else if (i == 'R' && isL) {
      cnt++;
      isL--;
    } else if (i == 'K' && isS) {
      cnt++;
      isS--;
    } else {
      break;
    }
  }
  cout << cnt;
  return 0;
}