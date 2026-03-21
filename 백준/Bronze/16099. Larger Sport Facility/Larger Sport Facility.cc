#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b > c * d)
      cout << "TelecomParisTech\n";
    else if (a * b < c * d)
      cout << "Eurecom\n";
    else
      cout << "Tie\n";
  }
  return 0;
}