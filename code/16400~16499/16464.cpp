#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    cout << (k & (k - 1) ? "Gazua\n" : "GoHanGang\n");
  }
  return 0;
}