#include <iostream>
using namespace std;

int main() {
  int n, result, cnt = 0;
  cin >> n;
  result = n;
  do {
    n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10;
    cnt++;
  } while (n != result);
  cout << cnt << '\n';
  return 0;
}