// 5358: Football Team
//
// - 문제
// The PLU football coach must submit to the NCAA officials the names of all players that will be competing in NCAA Division II championship game. Unfortunately his computer keyboard malfunctioned and interchanged the letters ‘i’ and ‘e’. Your job is to write a program that will read all the names and print the names with the correct spelling.
//
// - 입력
// The file contains a list of names, and each name will be on a separate line.
//
// - 출력
// Print the same list of names with every ‘i’ replaced with an ‘e’, every ‘e’ replaced with an ‘i’, every ‘I’ replaced with an ‘E’, and every ‘E’ replaced with an ‘I’.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    for (auto i : s)
      if (i == 'i')
        cout << 'e';
      else if (i == 'e')
        cout << 'i';
      else if (i == 'I')
        cout << 'E';
      else if (i == 'E')
        cout << 'I';
      else
        cout << i;
    cout << '\n';
  }
  return 0;
}