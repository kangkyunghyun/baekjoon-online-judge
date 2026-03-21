#include <iostream>
using namespace std;

int main() {
  int a;
  string b;
  cin >> a >> b;
  for (int i = 2; i >= 0; i--) {
    cout << a * (int)(b[i] - '0') << '\n';
  }
  cout << a * stoi(b) << '\n';
  return 0;
}