#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((b - a) % c ? (b - a) / c + 1 : (b - a) / c);
}