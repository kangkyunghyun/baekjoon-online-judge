#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 2)
      cout << "1 0\n";
    else
      cout << "0 1\n";
  }
  return 0;
}