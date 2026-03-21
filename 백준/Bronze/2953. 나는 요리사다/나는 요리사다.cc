#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int max = 0, index = 0;
  for (int i = 0; i < 5; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      int x;
      cin >> x;
      sum += x;
    }
    if (sum >= max) {
      max = sum;
      index = i + 1;
    }
  }
  cout << index << ' ' << max;
  return 0;
}