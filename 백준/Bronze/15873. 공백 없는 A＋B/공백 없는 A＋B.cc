#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int a, b;
  if (str.length() == 2) {
    a = str[0] - '0';
    b = str[1] - '0';
  } else if (str.length() == 3) {
    if (str[1] == '0') {
      a = 10;
      b = str[2] - '0';
    } else if (str[2] == '0') {
      a = str[0] - '0';
      b = 10;
    }
  } else if (str.length() == 4) {
    a = 10;
    b = 10;
  }
  cout << a + b << '\n';
  return 0;
}