#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  string ca[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
  for (int i = 0; i < 8; i++) {
    while (1) {
      int index = str.find(ca[i]);
      if (index == string::npos)
        break;
      str.replace(index, ca[i].length(), "*");
    }
  }
  cout << str.length() << '\n';
  return 0;
}