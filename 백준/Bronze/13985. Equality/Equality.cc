#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, ans;
  char op, temp;
  cin >> a >> op >> b >> temp >> c;
  switch (op) {
  case '+':
    ans = a + b;
    break;
  case '-':
    ans = a + -b;
    break;
  case '*':
    ans = a * b;
    break;
  case '/':
    ans = a / b;
    break;
  }
  if (ans == c)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}