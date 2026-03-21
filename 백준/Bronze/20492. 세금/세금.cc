#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (int)(n * 0.78) << ' ' << (int)(n - (n * 0.2 * 0.22)) << '\n';
  return 0;
}