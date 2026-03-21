#include <iostream>
using namespace std;

int main() {
  int a, b, v;
  cin >> a >> b >> v;
  if ((v - b) % (a - b) == 0) {
    cout << (v - b) / (a - b) << '\n';
  } else {
    cout << (v - b) / (a - b) + 1 << '\n';
  }
  return 0;
}