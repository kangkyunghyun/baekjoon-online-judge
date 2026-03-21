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