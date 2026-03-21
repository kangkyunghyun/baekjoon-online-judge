#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, result = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    int cnt = 0;
    for (int j = 1; j < a; j++) {
      if (a % j == 0)
        cnt++;
    }
    if (cnt == 1)
      result++;
  }
  cout << result << '\n';
  return 0;
}