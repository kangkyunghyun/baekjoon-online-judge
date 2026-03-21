#include <bits/stdc++.h>
using namespace std;

int main() {
  double arr[4], ans[4];
  double m = 0;
  int result, cnt = 0;
  for (int i = 0; i < 4; i++)
    cin >> arr[i];
  ans[0] = arr[0] / arr[2] + arr[1] / arr[3];
  ans[1] = arr[2] / arr[3] + arr[0] / arr[2];
  ans[2] = arr[3] / arr[1] + arr[2] / arr[0];
  ans[3] = arr[1] / arr[0] + arr[3] / arr[2];
  for (int i = 0; i < 4; i++)
    if (m < ans[i]) {
      m = ans[i];
      result = i;
    }
  for (int i = 0; i < 4; i++) {
    if (m == ans[i])
      cnt++;
  }
  if (cnt == 1)
    cout << result << '\n';
  else
    cout << -1 << '\n';
  return 0;
}