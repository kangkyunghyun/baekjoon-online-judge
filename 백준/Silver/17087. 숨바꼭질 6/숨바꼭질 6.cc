#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, s, d;
  cin >> n >> s >> d;
  d = abs(s - d);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    d = gcd(d, abs(s - x));
  }
  cout << d;
  return 0;
}