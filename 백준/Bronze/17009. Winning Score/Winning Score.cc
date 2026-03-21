#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, arr[2] = {0};
  for (int i = 0; i < 2; i++) {
    cin >> a >> b >> c;
    arr[i] = a * 3 + b * 2 + c;
  }
  if (arr[0] > arr[1])
    cout << 'A';
  else if (arr[0] < arr[1])
    cout << 'B';
  else
    cout << 'T';
  return 0;
}