#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, cnt = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      if (v[i] == i + 1)
        continue;
      int idx;
      for (int j = i + 1; j < n; j++)
        if (v[j] == i + 1) {
          idx = j;
          break;
        }
      swap(v[i], v[idx]);
      cnt++;
    }
    cout << (cnt % 2 ? "Minchan" : "Junee");
    return 0;
  }
  return 0;
}