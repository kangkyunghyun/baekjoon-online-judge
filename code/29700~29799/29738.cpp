#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    cout << "Case #" << i << ": ";
    if (n > 4500)
      cout << "Round 1";
    else if (n > 1000)
      cout << "Round 2";
    else if (n > 25)
      cout << "Round 3";
    else
      cout << "World Finals";
    cout << '\n';
  }
  return 0;
}