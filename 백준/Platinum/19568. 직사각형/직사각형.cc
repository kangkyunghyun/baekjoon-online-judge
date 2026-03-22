#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++)
      if (i == 15 && j < 14)
        cout << "1 ";
      else if (i == 15 && j > 14)
        cout << "15 ";
      else if (i < 15 && j == 14)
        cout << "225 ";
      else if (i > 15 && j == 14)
        cout << "3375 ";
      else
        cout << "0 ";
    cout << '\n';
  }
  return 0;
}