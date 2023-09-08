// 26489: Gum Gum for Jay Jay
//
// - 문제
// You are lost in the museum and keep walking by a giant rock head that says “gum gum for jay jay” each time you walk by. Print out the number of times you have walked by the giant rock head after reading in the data file.
//
// - 입력
// The data file will contain an unknown number of lines.
//
// - 출력
// Print out the number of lines in the data file.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int a = 0;
  while (getline(cin, s))
    a++;
  cout << a;
  return 0;
}