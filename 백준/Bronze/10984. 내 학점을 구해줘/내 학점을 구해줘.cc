#include <iostream>
using namespace std;

int main() {
  cout.precision(1);
  cout << fixed;
  int t, n, c, c_sum;
  float g, g_sum;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    c_sum = 0;
    g_sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> c >> g;
      c_sum += c;
      g_sum += g * c;
    }
    cout << c_sum << ' ' << g_sum / c_sum << '\n';
  }
  return 0;
}