#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long n, b, xSum = 0, ySum = 0, bSum = 0;
  cin >> n >> b;
  bSum = n * b;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    xSum += x;
    ySum += y;
  }
  if (xSum == 0) {
    cout << "EZPZ";
  } else if (bSum == ySum) {
    cout << 0;
  } else {
    long long left = xSum;
    long long right = ySum - bSum;
    if (right % left == 0) {
      cout << right / left;
    } else {
      long long d = gcd(left, right);
      long long p = right / d;
      long long q = left / d;
      if ((p < 0 && q > 0) || (p > 0 && q < 0))
        cout << '-' << abs(p) << '/' << abs(q);
      else
        cout << p << '/' << q;
    }
  }
  return 0;
}