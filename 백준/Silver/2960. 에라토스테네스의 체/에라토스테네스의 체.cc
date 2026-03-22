#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k, cnt = 0;
  cin >> n >> k;
  vector<int> v(n + 1, 1);
  for (int i = 2; i <= n; i++)
    if (v[i])
      for (int j = i; j <= n; j += i)
        if (v[j]) {
          v[j] = 0;
          cnt++;
          if (cnt == k) {
            cout << j;
            return 0;
          }
        }
  return 0;
}