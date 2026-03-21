#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, F, ans;
  cin >> N >> F;
  N -= N % 100;
  for (int i = 0; i < 100; i++) {
    if ((N + i) % F == 0) {
      ans = i;
      break;
    }
  }
  if (ans < 10)
    cout << 0;
  cout << ans << '\n';
  return 0;
}