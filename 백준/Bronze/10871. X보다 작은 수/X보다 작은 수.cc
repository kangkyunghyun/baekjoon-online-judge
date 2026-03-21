#include <iostream>
using namespace std;

int main() {
  int n, c, b;
  int a[10000] = {0};
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> b;
    a[i] = b;
  }
  for (int j = 0; j < n; j++) {
    if (a[j] < c) {
      cout << a[j] << '\n';
    }
  }
}