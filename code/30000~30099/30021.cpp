#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  if (n == 2)
    cout << "NO";
  else if (n == 1)
    cout << "YES\n1";
  else {
    cout << "YES\n1 3 2 ";
    for (int i = 4; i <= n; i++)
      cout << i << ' ';
  }
}