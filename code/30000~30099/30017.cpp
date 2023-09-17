#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  int i = 0;
  for (i = 1; i <= b && i + 1 <= a; i++)
    ;
  cout << 2 * (i - 1) + 1;
}