#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s, m, l;
  cin >> s >> m >> l;
  cout << (s + m * 2 + l * 3 >= 10 ? "happy" : "sad");
  return 0;
}