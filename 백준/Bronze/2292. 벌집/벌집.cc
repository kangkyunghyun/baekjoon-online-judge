#include <iostream>
using namespace std;

int main() {
  int n, wrap = 1, cnt = 1;
  cin >> n;
  while (n > wrap) {
    wrap += 6 * cnt;
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}