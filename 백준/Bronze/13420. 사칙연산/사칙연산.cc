#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    char d, e;
    cin >> a >> d >> b >> e >> c;
    if (d == '+') {
      if (a + b == c)
        cout << "correct\n";
      else
        cout << "wrong answer\n";
    } else if (d == '-') {
      if (a - b == c)
        cout << "correct\n";
      else
        cout << "wrong answer\n";
    } else if (d == '*') {
      if (a * b == c)
        cout << "correct\n";
      else
        cout << "wrong answer\n";
    } else if (d == '/') {
      if (a / b == c)
        cout << "correct\n";
      else
        cout << "wrong answer\n";
    }
  }
  return 0;
}