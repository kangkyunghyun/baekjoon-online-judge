#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3] = {0}, b;
  for (int i = 0; i < 3; i++) {
    cin >> b;
    a[b]++;
  }
  cout << (a[1] > a[2] ? 1 : 2);
  return 0;
}