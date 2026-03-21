#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x = 1;
  cin >> n;
  while (n > 0)
    x *= n--;
  cout << x;
  return 0;
}