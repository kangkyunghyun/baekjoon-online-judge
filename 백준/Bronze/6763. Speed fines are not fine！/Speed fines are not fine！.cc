#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int c = b - a;
  if (c > 0)
    cout << "You are speeding and your fine is $" << (c > 20 ? (c > 30 ? 500 : 270) : 100) << '.';
  else
    cout << "Congratulations, you are within the speed limit!";
  return 0;
}