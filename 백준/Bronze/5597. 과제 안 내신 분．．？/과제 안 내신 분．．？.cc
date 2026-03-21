#include <iostream>
using namespace std;

int main() {
  int n;
  int a[31] = {0};

  for (int i = 1; i <= 28; i++) {
    cin >> n;
    a[n] = 1;
  }
  for (int j = 1; j <= 30; j++) {
    if (a[j] == 0) {
      cout << j << '\n';
    }
  }
}