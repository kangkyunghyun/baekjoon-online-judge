#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (B >= C)
    cout << -1 << '\n';
  else
    cout << A / (C - B) + 1 << '\n';
  return 0;
}