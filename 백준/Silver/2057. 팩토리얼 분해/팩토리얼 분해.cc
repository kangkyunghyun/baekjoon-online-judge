#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  if (!n) {
    cout << "NO";
    return 0;
  }
  long long v[21] = {1, 1};
  for (int i = 2; i < 21; i++)
    v[i] = v[i - 1] * i;
  for (int i = 20; i >= 0; i--)
    if (n >= v[i])
      n -= v[i];
  cout << (n ? "NO" : "YES");
  return 0;
}