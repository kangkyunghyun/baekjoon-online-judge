#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[3] = {0};
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x + 1]++;
  }
  if (n % 2) {
    if (arr[1] > n / 2) {
      cout << "INVALID";
      return 0;
    }
  } else {
    if (arr[1] >= n / 2) {
      cout << "INVALID";
      return 0;
    }
  }
  if (arr[0] < arr[2])
    cout << "APPROVED";
  else
    cout << "REJECTED";
  return 0;
}