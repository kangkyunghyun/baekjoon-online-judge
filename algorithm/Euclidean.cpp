#include <bits/stdc++.h>
using namespace std;

// int gcd(int a, int b) {
//   if (b==0)
//     return a;
//   return gcd(b, a % b);
// }

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  cout << gcd(n, m) << ' ' << lcm(n, m);

  return 0;
}