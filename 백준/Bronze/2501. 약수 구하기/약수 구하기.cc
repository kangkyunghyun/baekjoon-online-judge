#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      v.push_back(i);
  cout << v[k - 1];
  return 0;
}