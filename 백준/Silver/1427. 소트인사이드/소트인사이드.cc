#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  sort(a.begin(), a.end(), greater<>());
  cout << a << '\n';
  return 0;
}