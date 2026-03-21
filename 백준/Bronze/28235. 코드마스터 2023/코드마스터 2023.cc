#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  if (s[0] == 'S')
    cout << "HIGHSCHOOL";
  else if (s[0] == 'C')
    cout << "MASTER";
  else if (s[0] == '2')
    cout << "0611";
  else
    cout << "CONTEST";
  return 0;
}