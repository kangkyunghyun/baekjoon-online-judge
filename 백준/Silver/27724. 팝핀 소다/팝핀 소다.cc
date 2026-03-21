#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  int round = log2(n);
  ans += log2(k);
  cout << min(ans + m, round);
  return 0;
}