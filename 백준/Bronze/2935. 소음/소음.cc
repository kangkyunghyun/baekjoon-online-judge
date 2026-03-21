#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string a, b;
  char c;
  cin >> a >> c >> b;
  if (c == '+') {
    if (a.size() > b.size()) {
      cout << 1;
      for (int i = 1; i < a.size() - b.size(); i++)
        cout << 0;
      cout << 1;
      for (int i = 1; i < b.size(); i++)
        cout << 0;
    } else if (a.size() < b.size()) {
      cout << 1;
      for (int i = 1; i < b.size() - a.size(); i++)
        cout << 0;
      cout << 1;
      for (int i = 1; i < a.size(); i++)
        cout << 0;
    } else {
      cout << 2;
      for (int i = 1; i < a.size(); i++)
        cout << 0;
    }
  } else {
    cout << 1;
    for (int i = 0; i < a.size() + b.size() - 2; i++)
      cout << 0;
  }

  return 0;
}