#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a;
  b = a;
  reverse(b.begin(), b.end());
  cout << (a == b);
  return 0;
}