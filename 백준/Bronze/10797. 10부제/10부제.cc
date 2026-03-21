#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, tmp, cnt = 0;
  cin >> d;
  for (int i = 0; i < 5; i++) {
    cin >> tmp;
    if (tmp == d)
      cnt++;
  }
  cout << cnt;
  return 0;
}