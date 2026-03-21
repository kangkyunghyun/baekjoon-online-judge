#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

void weirdPrime(int first, int cnt) {
  if (!cnt) {
    cout << first << '\n';
    return;
  }
  for (int i = 1; i < 10; i += 2) {
    int num = first * 10 + i;
    if (isPrime(num))
      weirdPrime(num, cnt - 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  int arr[] = {2, 3, 5, 7};
  for (int i : arr)
    weirdPrime(i, n - 1);
  return 0;
}