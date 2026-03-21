#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  if (s.find('M') != -1)
    if (s.find('O') != -1)
      if (s.find('B') != -1)
        if (s.find('I') != -1)
          if (s.find('S') != -1) {
            cout << "YES";
            return 0;
          }
  cout << "NO";
  return 0;
}