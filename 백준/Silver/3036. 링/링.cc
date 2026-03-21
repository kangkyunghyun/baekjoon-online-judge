#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, a;
  cin >> n >> a;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    int d = gcd(a, x);
    cout << a / d << '/' << x / d << '\n';
  }
  return 0;
}