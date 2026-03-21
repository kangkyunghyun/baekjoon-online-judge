#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  cout << min(n, a) + min(n, b) + min(n, c);
  return 0;
}