#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> isPrime(5000001, 1), prime;
  for (int i = 2; i * i <= 5000000; i++)
    if (isPrime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= 5000000; j += i)
        isPrime[j] = 0;
    }
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    while (x > 1)
      if (isPrime[x]) {
        cout << x;
        x = 1;
      } else {
        for (int i : prime)
          if (x % i == 0) {
            cout << i << ' ';
            x /= i;
            break;
          }
      }
    cout << '\n';
  }
  return 0;
}