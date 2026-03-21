#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  cout << n - 1 + (n - 2) * (n - 1) << '\n';
  for (int i = 2; i <= n; i++)
    cout << "1 " << i << '\n';
  return 0;
}