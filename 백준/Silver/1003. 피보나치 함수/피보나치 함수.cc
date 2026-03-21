#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  int zero[41] = {1, 0};
  int one[41] = {0, 1};
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 2; j <= n; j++) {
      zero[j] = zero[j - 1] + zero[j - 2];
      one[j] = one[j - 1] + one[j - 2];
    }
    cout << zero[n] << ' ' << one[n] << '\n';
  }
  return 0;
}