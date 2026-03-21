#include <iostream>
using namespace std;

int main() {
  int n, x, b;
  int a[10000] = {0};
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> b;
    a[i] = b;
  }
  for (int j = 0; j < n; j++) {
    if (a[j] < x) {
      cout << a[j] << ' ';
    }
  }
}