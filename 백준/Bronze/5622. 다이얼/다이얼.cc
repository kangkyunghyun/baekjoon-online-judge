#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int t = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C') {
      t += 3;
    } else if (str[i] == 'D' || str[i] == 'E' || str[i] == 'F') {
      t += 4;
    } else if (str[i] == 'G' || str[i] == 'H' || str[i] == 'I') {
      t += 5;
    } else if (str[i] == 'J' || str[i] == 'K' || str[i] == 'L') {
      t += 6;
    } else if (str[i] == 'M' || str[i] == 'N' || str[i] == 'O') {
      t += 7;
    } else if (str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S') {
      t += 8;
    } else if (str[i] == 'T' || str[i] == 'U' || str[i] == 'V') {
      t += 9;
    } else if (str[i] == 'W' || str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z') {
      t += 10;
    }
  }
  cout << t << '\n';
  return 0;
}