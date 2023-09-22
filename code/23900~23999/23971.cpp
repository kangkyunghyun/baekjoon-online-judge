#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w, h, n, m;
  cin >> w >> h >> n >> m;
  cout << ((w + n) / (n + 1)) * ((h + m) / (m + 1));
  return 0;
}