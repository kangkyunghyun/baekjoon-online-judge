#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> s;
  int ub = 0;
  for (char i : s)
    if (i == '_')
      ub++;
  cout << s.length() + 2 + ub * 5;
  return 0;
}