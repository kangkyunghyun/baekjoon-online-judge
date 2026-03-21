#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, arr[4] = {0};
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
      arr[3]++;
    else if (b == 1 || b == 2)
      arr[0]++;
    else if (b == 3)
      arr[1]++;
    else
      arr[2]++;
  }
  for (int i : arr)
    cout << i << '\n';
  return 0;
}