#include <bits/stdc++.h>
using namespace std;
#define INF 2000000001

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, e = INF, o = INF;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int d = abs(v[i] - v[j]);
      if (d % 2)
        o = min(o, d);
      else
        e = min(e, d);
    }
  if (e == INF)
    e = -1;
  if (o == INF)
    o = -1;
  cout << e << ' ' << o;
  return 0;
}