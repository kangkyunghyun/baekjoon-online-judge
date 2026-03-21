#include <bits/stdc++.h>
using namespace std;

int hansu(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    string str = to_string(i);
    if (i < 100) {
      cnt++;
    } else if (str[1] - str[0] == str[2] - str[1]) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  cout << hansu(n) << '\n';
  return 0;
}