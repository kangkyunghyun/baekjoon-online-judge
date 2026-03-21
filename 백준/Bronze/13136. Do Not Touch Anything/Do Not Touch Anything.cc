#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long r, c, n;
  cin >> r >> c >> n;
  cout << (long long)(ceil((double)r / n) * ceil((double)c / n));
  return 0;
}