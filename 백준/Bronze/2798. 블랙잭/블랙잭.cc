#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (v[i] + v[j] + v[k] <= m)
          if (ans < v[i] + v[j] + v[k])
            ans = v[i] + v[j] + v[k];
  cout << ans;
  return 0;
}