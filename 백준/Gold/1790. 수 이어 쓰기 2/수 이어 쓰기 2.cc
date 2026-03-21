#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int sum = 0, c = 1, d = 10, ans = -1;
  for (int i = 1; i <= n; i++) {
    if (i % d == 0) {
      d *= 10;
      c++;
    }
    sum += c;
    if (sum >= k) {
      string s = to_string(i);
      int index = s.size() - sum + k - 1;
      ans = s[index] - '0';
      break;
    }
  }
  cout << ans;
  return 0;
}