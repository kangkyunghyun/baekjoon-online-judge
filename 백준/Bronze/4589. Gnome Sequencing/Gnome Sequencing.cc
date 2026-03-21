#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << "Gnomes:\n";
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a <= b && b <= c) || (a >= b && b >= c) ? "Ordered\n" : "Unordered\n");
  }
  return 0;
}