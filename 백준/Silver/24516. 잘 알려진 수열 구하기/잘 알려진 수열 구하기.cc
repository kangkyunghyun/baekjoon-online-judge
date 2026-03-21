#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x = 2;
  cin >> n;
  while (n--) {
    cout << x << ' ';
    x += 2;
  }
  return 0;
}