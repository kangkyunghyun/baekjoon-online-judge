#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int s, t, d;
  cin >> s >> t >> d;
  cout << (d / (s * 2)) * t;
  return 0;
}