#include <iostream>
using namespace std;

int main() {
  string a, b, c = "000", d = "000";
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    c[a.length() - 1 - i] = a[i];
  }
  for (int i = 0; i < a.length(); i++) {
    d[a.length() - 1 - i] = b[i];
  }
  if (stoi(c) > stoi(d)) {
    cout << c << '\n';
  } else {
    cout << d << '\n';
  }
  return 0;
}