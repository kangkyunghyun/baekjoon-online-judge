#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, a = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    a *= i;
  cout << a / (7 * 24 * 60 * 60);
  return 0;
}