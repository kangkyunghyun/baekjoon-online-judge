#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  map<int, bool> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m.insert(make_pair(x, true));
  }
  for (pair<int, bool> i : m)
    cout << i.first << ' ';
  return 0;
}