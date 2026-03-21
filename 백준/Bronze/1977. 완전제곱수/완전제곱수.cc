#include <iostream>
using namespace std;

int main() {
  int min = 10001, m, n, sum = 0, cnt = 0;
  cin >> m >> n;
  for (int i = 1; i <= 100; i++) {
    if (i * i >= m && i * i <= n) {
      sum += i * i;
      cnt++;
      if (i * i < min) {
        min = i * i;
      }
    }
  }
  if (cnt == 0) {
    cout << -1 << '\n';
  } else {
    cout << sum << '\n'
         << min << '\n';
  }
  return 0;
}