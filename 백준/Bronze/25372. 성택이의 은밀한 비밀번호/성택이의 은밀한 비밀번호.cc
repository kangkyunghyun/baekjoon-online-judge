#include <iostream>
using namespace std;

int main() {
  int n;
  string a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a.length() >= 6 && a.length() <= 9) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
  return 0;
}