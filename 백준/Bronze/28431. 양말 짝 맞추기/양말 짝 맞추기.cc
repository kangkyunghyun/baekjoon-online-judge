#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[10] = {0}, x;
  for (int i = 0; i < 5; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 0; i < 10; i++)
    if (a[i] % 2)
      cout << i;
  return 0;
}